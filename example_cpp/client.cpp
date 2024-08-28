
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    std::string pipeline = "udpsrc port=5000 caps=\"application/x-rtp, encoding-name=H264, payload=96\" ! rtph264depay ! avdec_h264 ! videoconvert ! appsink";

    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        std::cerr << "Could not open GStreamer pipeline for reading" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Received empty frame" << std::endl;
            break;
        }

        cv::imshow("Client", frame);

        char c = (char)cv::waitKey(1);
        if (c == 27) // Arrêter si l'utilisateur appuie sur Échap
            break;
    }

    cap.release();
    return 0;
}
