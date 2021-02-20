#include <cstdio>
#include <cstring>
#include <ctime>

#include "ColorListener.hpp"

int main(int argc, char **argv) {
    char filename[12];  // MMDD-hhmmss
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(filename, "%02d%02d-%02d%02d%02d", ltm->tm_mon, ltm->tm_mday,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    astra::initialize();

    astra::StreamSet streamSet;
    astra::StreamReader reader = streamSet.create_reader();
    ColorListener cListener(filename);
    reader.stream<astra::ColorStream>().start();
    reader.add_listener(cListener);
    for (int i = 0; i < 2; i++) {
        astra_update();
    }
    reader.remove_listener(cListener);
    astra::terminate();
    cv::Mat a;

    // return model(argc, argv);
}
