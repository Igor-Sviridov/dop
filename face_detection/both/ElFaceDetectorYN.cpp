#include "ElFaceDetectorYN.hpp"

ElFaceDetectorYN::ElFaceDetectorYN(
                    const std::string& model_graph_path,
                    const std::string& model_weights_path,
                    const cv::Size& input_size,
                    float score_threshold,
                    float nms_threshold,
                    int top_k)
{
    std::cout<< "loading model: " << model_graph_path << " | " << model_weights_path << std::endl;
    modelId = LoadModel(model_graph_path.c_str(), model_weights_path.c_str());
    std::cout<< "load model done" << std::endl;

    inputW = input_size.width;
    inputH = input_size.height;

    uint32_t shape[5];
    for (int i =0; i < 5; i ++)
    {
        shape[i]  = 0;
    }
    GetInputShape(modelId, 0,  shape);
    std::cout << "Input shape: " << shape[2] << " " << shape[3] << " " << shape[4] << std::endl;
    // shape[1] - batch size
    modelInC = shape[2];
    modelInH = shape[3];
    modelInW = shape[4];

    
    for(auto i = 0; i < 3; i++)
    {
        GetOutputShape(modelId, i,  shape);
        CV_CheckEQ(shape[0], 2, "output ndim is wrong. Expected 2.");
        std::cout << "Out shape " << i << " : "  << shape[1] << " " << shape[2] << std::endl; 
        modelOutH[i] = shape[1];
        modelOutW[i] = shape[2];
    }
    std::cout << "11 shape " << std::endl;
    output[0] = new float[modelOutH[0]*modelOutW[0]];  // loc
    std::cout << "111 shape " << std::endl;
    output[1] = new float[modelOutH[1]*modelOutW[1]];  // conf
    output[2] = new float[modelOutH[2]*modelOutW[2]];  // iou

    scoreThreshold = score_threshold;
    nmsThreshold = nms_threshold;
    topK = top_k;
    
    generatePriors();
}

ElFaceDetectorYN::~ElFaceDetectorYN()
{
    for(auto i = 0; i < 3; i++)
    {
        delete [] output[i];
    }
}

void ElFaceDetectorYN::setInputSize(const cv::Size& input_size)
{
    inputW = input_size.width;
    inputH = input_size.height;
}

cv::Size ElFaceDetectorYN::getInputSize()
{
    cv::Size input_size;
    input_size.width = inputW;
    input_size.height = inputH;
    return input_size;
}

void ElFaceDetectorYN::setScoreThreshold(float score_threshold)
{
    scoreThreshold = score_threshold;
}

float ElFaceDetectorYN::getScoreThreshold()
{
    return scoreThreshold;
}

void ElFaceDetectorYN::setNMSThreshold(float nms_threshold)
{
    nmsThreshold = nms_threshold;
}

float ElFaceDetectorYN::getNMSThreshold()
{
    return nmsThreshold;
}

void ElFaceDetectorYN::setTopK(int top_k)
{
    topK = top_k;
}

int ElFaceDetectorYN::getTopK()
{
    return topK;
}

int ElFaceDetectorYN::detect(cv::InputArray input_image, cv::OutputArray faces)
{
    // TODO: more checkings should be done?
    if (input_image.empty())
    {
        return 0;
    }
    // CV_CheckEQ(input_image.size(), cv::Size(modelInW, modelInH), "Size does not match.");

    // Build blob from input image
    cv::Mat resized_image;
    cv::resize(input_image, resized_image, cv::Size(modelInW, modelInH), 0, 0, cv::INTER_LINEAR);
    cv::Mat input_blob = cv::dnn::blobFromImage(resized_image);

    std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::milliseconds> start;
    std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::milliseconds> stop;
    // Forward
    std::vector<cv::Mat> output_blobs_el;

    input = (float*)input_blob.data;

    // start = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    InvokeModel(modelId, &input, output, 1);
    // stop = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    // std::cout<<"InvokeModel done, time: " << (stop - start).count() <<" milliseconds;"<<std::endl;
    
    // Post process
    // std::cout<<"running postProcess el"<<std::endl;
    // start = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    cv::Mat results_el = postProcess(output[0], output[1], output[2]);
    results_el.convertTo(faces, CV_32FC1);
    // stop = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    // std::cout<<"postProcess el done, time: " << (stop - start).count() <<" milliseconds;"<<std::endl;


    return 1;
}

void ElFaceDetectorYN::generatePriors()
{
    // Calculate shapes of different scales according to the shape of input image
    cv::Size feature_map_2nd = {
        int(int((modelInW+1)/2)/2), int(int((modelInH+1)/2)/2)
    };
    cv::Size feature_map_3rd = {
        int(feature_map_2nd.width/2), int(feature_map_2nd.height/2)
    };
    cv::Size feature_map_4th = {
        int(feature_map_3rd.width/2), int(feature_map_3rd.height/2)
    };
    cv::Size feature_map_5th = {
        int(feature_map_4th.width/2), int(feature_map_4th.height/2)
    };
    cv::Size feature_map_6th = {
        int(feature_map_5th.width/2), int(feature_map_5th.height/2)
    };

    std::vector<cv::Size> feature_map_sizes;
    feature_map_sizes.push_back(feature_map_3rd);
    feature_map_sizes.push_back(feature_map_4th);
    feature_map_sizes.push_back(feature_map_5th);
    feature_map_sizes.push_back(feature_map_6th);

    // Fixed params for generating priors
    const std::vector<std::vector<float>> min_sizes = {
        {10.0f,  16.0f,  24.0f},
        {32.0f,  48.0f},
        {64.0f,  96.0f},
        {128.0f, 192.0f, 256.0f}
    };
    CV_Assert(min_sizes.size() == feature_map_sizes.size()); // just to keep vectors in sync
    const std::vector<int> steps = { 8, 16, 32, 64 };

    // Generate priors
    priors.clear();
    for (size_t i = 0; i < feature_map_sizes.size(); ++i)
    {
        cv::Size feature_map_size = feature_map_sizes[i];
        std::vector<float> min_size = min_sizes[i];

        for (int _h = 0; _h < feature_map_size.height; ++_h)
        {
            for (int _w = 0; _w < feature_map_size.width; ++_w)
            {
                for (size_t j = 0; j < min_size.size(); ++j)
                {
                    float s_kx = min_size[j] / modelInW;
                    float s_ky = min_size[j] / modelInH;

                    float cx = (_w + 0.5f) * steps[i] / modelInW;
                    float cy = (_h + 0.5f) * steps[i] / modelInH;

                    cv::Rect2f prior = { cx, cy, s_kx, s_ky };
                    priors.push_back(prior);
                }
            }
        }
    }
}
cv::Mat ElFaceDetectorYN::postProcess(const float* loc, const float* conf, const float* iou)
{
    // Decode from deltas and priors
    const std::vector<float> variance = {0.1f, 0.2f};
    cv::Mat faces;
    // (tl_x, tl_y, w, h, re_x, re_y, le_x, le_y, nt_x, nt_y, rcm_x, rcm_y, lcm_x, lcm_y, score)
    // 'tl': top left point of the bounding box
    // 're': right eye, 'le': left eye
    // 'nt':  nose tip
    // 'rcm': right corner of mouth, 'lcm': left corner of mouth
    cv::Mat face(1, 15, CV_32FC1);
    for (size_t i = 0; i < priors.size(); ++i) {
        // Get score
        float clsScore = conf[i*2+1];
        float iouScore = iou[i];
        // Clamp
        if (iouScore < 0.f) {
            iouScore = 0.f;
        }
        else if (iouScore > 1.f) {
            iouScore = 1.f;
        }
        float score = std::sqrt(clsScore * iouScore);
        face.at<float>(0, 14) = score;

        // Get bounding box
        float cx = (priors[i].x + loc[i*14+0] * variance[0] * priors[i].width)  * inputW;
        float cy = (priors[i].y + loc[i*14+1] * variance[0] * priors[i].height) * inputH;
        float w  = priors[i].width  * exp(loc[i*14+2] * variance[0]) * inputW;
        float h  = priors[i].height * exp(loc[i*14+3] * variance[1]) * inputH;
        float x1 = cx - w / 2;
        float y1 = cy - h / 2;
        face.at<float>(0, 0) = x1;
        face.at<float>(0, 1) = y1;
        face.at<float>(0, 2) = w;
        face.at<float>(0, 3) = h;

        // Get landmarks
        face.at<float>(0, 4) = (priors[i].x + loc[i*14+ 4] * variance[0] * priors[i].width)  * inputW;  // right eye, x
        face.at<float>(0, 5) = (priors[i].y + loc[i*14+ 5] * variance[0] * priors[i].height) * inputH;  // right eye, y
        face.at<float>(0, 6) = (priors[i].x + loc[i*14+ 6] * variance[0] * priors[i].width)  * inputW;  // left eye, x
        face.at<float>(0, 7) = (priors[i].y + loc[i*14+ 7] * variance[0] * priors[i].height) * inputH;  // left eye, y
        face.at<float>(0, 8) = (priors[i].x + loc[i*14+ 8] * variance[0] * priors[i].width)  * inputW;  // nose tip, x
        face.at<float>(0, 9) = (priors[i].y + loc[i*14+ 9] * variance[0] * priors[i].height) * inputH;  // nose tip, y
        face.at<float>(0, 10) = (priors[i].x + loc[i*14+10] * variance[0] * priors[i].width)  * inputW; // right corner of mouth, x
        face.at<float>(0, 11) = (priors[i].y + loc[i*14+11] * variance[0] * priors[i].height) * inputH; // right corner of mouth, y
        face.at<float>(0, 12) = (priors[i].x + loc[i*14+12] * variance[0] * priors[i].width)  * inputW; // left corner of mouth, x
        face.at<float>(0, 13) = (priors[i].y + loc[i*14+13] * variance[0] * priors[i].height) * inputH; // left corner of mouth, y

        faces.push_back(face);
    }

    if (faces.rows > 1)
    {
        // Retrieve boxes and scores
        std::vector<cv::Rect2i> faceBoxes;
        std::vector<float> faceScores;
        for (int rIdx = 0; rIdx < faces.rows; rIdx++)
        {
            faceBoxes.push_back(cv::Rect2i(int(faces.at<float>(rIdx, 0)),
                                        int(faces.at<float>(rIdx, 1)),
                                        int(faces.at<float>(rIdx, 2)),
                                        int(faces.at<float>(rIdx, 3))));
            faceScores.push_back(faces.at<float>(rIdx, 14));
        }

        std::vector<int> keepIdx;
        cv::dnn::NMSBoxes(faceBoxes, faceScores, scoreThreshold, nmsThreshold, keepIdx, 1.f, topK);

        // Get NMS results
        cv::Mat nms_faces;
        for (int idx: keepIdx)
        {
            nms_faces.push_back(faces.row(idx));
        }
        return nms_faces;
    }
    else
    {
        return faces;
    }
}
