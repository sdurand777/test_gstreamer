
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    cv::VideoWriter writer;

    std::string pipeline = "appsrc ! videoconvert ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast ! rtph264pay ! udpsink host=127.0.0.1 port=5000";
    
    writer.open(pipeline, 0, 30, cv::Size(640, 480), true);

    if (!writer.isOpened()) {
        std::cerr << "Could not open GStreamer pipeline for writing" << std::endl;
        return -1;
    }

    // cv::Mat frame;
    // while (true) {
    //     // Génère une image de test
    //     frame = cv::Mat::zeros(480, 640, CV_8UC3);
    //     cv::putText(frame, "Test Stream", cv::Point(200, 240), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);
    //     
    //     writer.write(frame);
    //
    //     char c = (char)cv::waitKey(1);
    //     if (c == 27) // Arrêter si l'utilisateur appuie sur Échap
    //         break;
    // }



    cv::Mat frame;
    int frameCount = 0;
    while (true) {
        // Génère une image de test
        frame = cv::Mat::zeros(480, 640, CV_8UC3);

        // Crée une couleur qui change à chaque frame
        cv::Scalar textColor((frameCount * 10) % 256, (frameCount * 20) % 256, (frameCount * 30) % 256);

        cv::putText(frame, "Test Stream", cv::Point(200, 240), cv::FONT_HERSHEY_SIMPLEX, 1.0, textColor, 2);

        writer.write(frame);

        frameCount++;

        char c = (char)cv::waitKey(1);
        if (c == 27) // Arrêter si l'utilisateur appuie sur Échap
            break;
    }

    writer.release();
    return 0;
}
