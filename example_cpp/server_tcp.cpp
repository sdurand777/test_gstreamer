
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    cv::VideoWriter writer;

    std::string pipeline = "appsrc ! videoconvert ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast ! mpegtsmux ! tcpserversink host=127.0.0.1 port=5000 sync=false";

    writer.open(pipeline, 0, 30, cv::Size(640, 480), true);

    if (!writer.isOpened()) {
        std::cerr << "Could not open GStreamer pipeline for writing" << std::endl;
        return -1;
    }

    cv::Mat frame;
    int frameCount = 0;
    while (true) {
        frame = cv::Mat::zeros(480, 640, CV_8UC3);
        cv::Scalar textColor((frameCount * 10) % 256, (frameCount * 20) % 256, (frameCount * 30) % 256);
        cv::putText(frame, "Test Stream", cv::Point(200, 240), cv::FONT_HERSHEY_SIMPLEX, 1.0, textColor, 2);
        writer.write(frame);
        frameCount++;

        char c = (char)cv::waitKey(1);
        if (c == 27)
            break;
    }

    writer.release();
    return 0;
}



