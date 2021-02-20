#ifndef COLORLISTENER_HPP
#define COLORLISTENER_HPP
#include <astra/astra.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
class ColorListener : public astra::FrameListener {
  private:
    const char* path;
    int count;

  public:
    ColorListener(const char* p);
    ~ColorListener();
    void on_frame_ready(astra::StreamReader& reader, astra::Frame& frame);
};

#endif