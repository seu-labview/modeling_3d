#include "Listener.hpp"

DepthListener::DepthListener(const char* p) {
    path = p;
    count = 0;
}

DepthListener::~DepthListener() {
}

void DepthListener::on_frame_ready(astra::StreamReader& reader,
                                   astra::Frame& frame) {
    const astra::DepthFrame depthFrame = frame.get<astra::DepthFrame>();
    int width = depthFrame.width();
    int height = depthFrame.height();

    const int16_t* depthData = depthFrame.data();
    cv::Mat frameMat(cv::Size(width, height), CV_16SC1);
    int16_t* p = frameMat.ptr<int16_t>();
    for (int i = 0; i < width * height; i++) {
        p[i] = depthData[i];
    }
    char picname[50];
    sprintf(picname, "%s%d_depth.png", path, count);
    cv::imwrite(picname, frameMat);
    count++;
}