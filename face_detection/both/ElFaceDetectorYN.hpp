#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/dnn.hpp>
#include <algorithm>
#include <iostream>
#include <elcorenn/elcorenn.h>
#include <string>

#pragma once

class ElFaceDetectorYN : public cv::FaceDetectorYN
{
public:
    ElFaceDetectorYN(   const std::string& model_graph_path,
                        const std::string& model_weights_path,
                        const cv::Size& input_size,
                        float score_threshold,
                        float nms_threshold,
                        int top_k);
    ~ElFaceDetectorYN() override;
    void setInputSize(const cv::Size& input_size) override;
    cv::Size getInputSize() override;                        
    void setScoreThreshold(float score_threshold) override;
    float getScoreThreshold() override;
    void setNMSThreshold(float nms_threshold) override;
    float getNMSThreshold() override;
    void setTopK(int top_k) override;
    int getTopK() override;
    int detect(cv::InputArray input_image, cv::OutputArray faces) override;

private:
    void generatePriors();   
    cv::Mat postProcess(const float* loc_v, const float* conf_v, const float* iou_v);

  
private:
    ENNModelId modelId;
    uint32_t inputW;
    uint32_t inputH;
    uint32_t modelInW;
    uint32_t modelInH;
    uint32_t modelInC;
    uint32_t modelOutW[3];
    uint32_t modelOutH[3];
    float scoreThreshold;
    float nmsThreshold;
    int topK;
    std::vector<cv::Rect2f> priors;
    float*  input;
    float* output[3];
};
