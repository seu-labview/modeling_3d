#include "ColorListener.hpp"

ColorListener::ColorListener(const char* p) {
    path = p;
    count = 0;
}

ColorListener::~ColorListener() {}

void ColorListener::on_frame_ready(astra::StreamReader& reader,
                                   astra::Frame& frame) {
    const astra::ColorFrame colorFrame = frame.get<astra::ColorFrame>();
    int width = colorFrame.width();
    int height = colorFrame.height();

    const astra::RgbPixel* colorData = colorFrame.data();
    cv::Mat frameMat(cv::Size(width, height), CV_8UC3);
    uchar* p = frameMat.ptr<uchar>();
    for (int i = 0; i < width * height; i++) {
        p[i * 3] = colorData[i].b;
        p[i * 3 + 1] = colorData[i].g;
        p[i * 3 + 2] = colorData[i].r;
    }
    char picname[20];
    sprintf(picname, "%s%d.jpg", path, count);
    cv::imwrite(picname, frameMat);
    count++;
}