#include <getopt.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <ctime>

#include "Listener.hpp"

int main(int argc, char **argv) {
    // get options
    char *dirname;
    static struct option long_options[] = {
        {"dir", required_argument, NULL, 'd'}, {0, 0}};
    static char *const short_options = (char *)"d:";
    int ret = 0, option_index = 0;
    while ((ret = getopt_long(argc, argv, short_options, long_options,
                              &option_index)) != -1) {
        switch (ret) {
            case 'd':
                dirname = optarg;
            default:
                break;
        }
    }

    // set output path
    char filename[50];  // dir/MMDD-hhmmss
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(filename, "%s/%02d%02d-%02d%02d%02d", dirname, ltm->tm_mon,
            ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    struct stat sb;
    if (stat(dirname, &sb)) {
        mkdir(dirname, S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
    }

    astra::initialize();
    astra::StreamSet streamSet;
    astra::StreamReader cReader = streamSet.create_reader();
    astra::StreamReader dReader = streamSet.create_reader();
    ColorListener cListener(filename);
    DepthListener dListener(filename);
    cReader.stream<astra::ColorStream>().start();
    dReader.stream<astra::DepthStream>().start();
    cReader.add_listener(cListener);
    dReader.add_listener(dListener);

    printf("\n");
    cv::Mat tmp;
    for (int i = 0; i < 100; i++) {
        astra_update();
        printf("\r%03d/100", i);
        usleep(200000);  // shot every 200ms
        tmp = cv::imread("tmp.png");
        cv::imshow(dirname, tmp);
    }
    
    cReader.remove_listener(cListener);
    dReader.remove_listener(dListener);
    astra::terminate();
    cv::destroyAllWindows();
}
