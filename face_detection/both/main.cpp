#include "opencv2/opencv.hpp"
#include <opencv2/highgui.hpp>

#include <opencv2/core.hpp>


#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/dnn.hpp>

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <elcorenn/elcorenn.h>
#include "ElFaceDetectorYN.hpp"

cv::Mat visualize(const cv::Mat& image, const cv::Mat& faces, float fps = -1.f)
{
    static cv::Scalar box_color{0, 255, 0};
    static std::vector<cv::Scalar> landmark_color{
        cv::Scalar(255,   0,   0), // right eye
        cv::Scalar(  0,   0, 255), // left eye
        cv::Scalar(  0, 255,   0), // nose tip
        cv::Scalar(255,   0, 255), // right mouth corner
        cv::Scalar(  0, 255, 255)  // left mouth corner
    };
    static cv::Scalar text_color{0, 255, 255};

    auto output_image = image.clone();

    if (fps >= 0)
    {
        cv::putText(output_image, cv::format("FPS: %.2f", fps), cv::Point(0, 15), cv::FONT_HERSHEY_SIMPLEX, 0.5, text_color, 2);
    }

    for (int i = 0; i < faces.rows; ++i)
    {
        // Draw bounding boxes
        int x1 = static_cast<int>(faces.at<float>(i, 0));
        int y1 = static_cast<int>(faces.at<float>(i, 1));
        int w = static_cast<int>(faces.at<float>(i, 2));
        int h = static_cast<int>(faces.at<float>(i, 3));
        cv::rectangle(output_image, cv::Rect(x1, y1, w, h), box_color, 2);

        // Confidence as text
        float conf = faces.at<float>(i, 14);
        cv::putText(output_image, cv::format("%.4f", conf), cv::Point(x1, y1+12), cv::FONT_HERSHEY_DUPLEX, 0.5, text_color);

        // Draw landmarks
        for (int j = 0; j < landmark_color.size(); ++j)
        {
            int x = static_cast<int>(faces.at<float>(i, 2*j+4)), y = static_cast<int>(faces.at<float>(i, 2*j+5));
            cv::circle(output_image, cv::Point(x, y), 2, landmark_color[j], 2);
        }
    }
    return output_image;
}

int main(int argc, char** argv)
{
    cv::CommandLineParser parser(argc, argv,
        "{help  h           |  <none>                           | Print this message}"
        "{backend b         |  <none>                           | 'elcorenn' or 'opencv'  backend}"
        "{input i           |  <none>                           | Set input to a certain image}"
        "{output o          |  <none>                           | Set output path for image}"
        "{model m           |  <none>                           | Set path to the model folder.}"
        /* model params below*/
        "{conf_threshold    | 0.9                               | Set the minimum confidence for the model to identify a face. Filter out faces of conf < conf_threshold}"
        "{nms_threshold     | 0.3                               | Set the threshold to suppress overlapped boxes. Suppress boxes if IoU(box1, box2) >= nms_threshold, the one of higher score is kept.}"
        "{top_k             | 5000                              | Keep top_k bounding boxes before NMS. Set a lower value may help speed up postprocessing.}"
    );
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }

    std::string input_path = parser.get<std::string>("input");
    std::string output_path = parser.get<std::string>("output");
    std::string model_path = parser.get<std::string>("model");
    std::string backend = parser.get<std::string>("backend");
    
    // model params
    float conf_threshold = parser.get<float>("conf_threshold");
    float nms_threshold = parser.get<float>("nms_threshold");
    int top_k = parser.get<int>("top_k");
    cv::Ptr<cv::FaceDetectorYN> model;
    //Instantiate YuNet
    uint32_t ElcoreBackendId = 0;
    uint32_t dev = 0;


    std::cout << "image path is " << input_path << std::endl;
    cv::Mat image = cv::imread(input_path);

    cv::Size image_size = image.size();

    if(backend == "elcorenn")
    {
        std::cout << "Using ElcoreNN as backend!" << std::endl;
        ElcoreBackendId = InitBackend(1, &dev);
        std::cout << "model path is " << model_path << std::endl;
        model = cv::makePtr<ElFaceDetectorYN>(model_path + "/model.json", model_path + "/model.bin", image_size, conf_threshold, nms_threshold, top_k);
    }
    else if (backend == "opencv")
    {
        std::cout << "Using OpenCV as backend!" << std::endl;
        model = cv::FaceDetectorYN::create(model_path + "/model.onnx", "", image_size, conf_threshold, nms_threshold, top_k, 0, 0);
    }
    else
    {
        throw std::invalid_argument("Unknown backend. Use '-h' to see valid backand options.");
    }


    

    // Inference
    cv::Mat faces;
    std::cout<<"running detect"<<std::endl;
    auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    model->detect(image, faces);
    auto stop = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    std::cout<<"detect done, time: " << (stop - start).count() <<" milliseconds;"<<std::endl;


    // Print faces
    std::cout << cv::format("%d faces detected:\n", faces.rows);
    for (int i = 0; i < faces.rows; ++i)
    {
        int x1 = static_cast<int>(faces.at<float>(i, 0));
        int y1 = static_cast<int>(faces.at<float>(i, 1));
        int w = static_cast<int>(faces.at<float>(i, 2));
        int h = static_cast<int>(faces.at<float>(i, 3));
        float conf = faces.at<float>(i, 14);
        std::cout << cv::format("%d: x1=%d, y1=%d, w=%d, h=%d, conf=%.4f\n", i, x1, y1, w, h, conf);
    }

    // Draw reults on the input image
    auto res_image = visualize(image, faces);

    imwrite(output_path, res_image);

    if(backend == "elcorenn")
    {
        ReleaseBackend(ElcoreBackendId);       
    }

    return 0;
}

