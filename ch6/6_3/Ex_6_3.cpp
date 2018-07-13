#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void help(char** argv ) {
    std::cout << "\n"
              << "Read in a video.\n"
              << argv[0] <<" <path/video> <paht/video_output>\n"
              << std::endl;
}

int main( int argc, char** argv ) {

    if (argc != 2) {
        help(argv);
        return 0;
    }

    cv::VideoCapture cap;
    cap.open(std::string(argv[1]));
    double fps = cap.get(cv::CAP_PROP_FPS);
    cv::Mat frame;

    while(1)
    {
        cap >> frame;
        if(frame.empty()) break;
        cv::putText(frame, "FPS: " + std::to_string(fps), cv::Point(10, 50), cv::FONT_HERSHEY_PLAIN, 1.5, cv::Scalar(0,0,255), 2);
        cv::imshow("Ex_6_3", frame);
        char c = cv::waitKey(1000/fps);
        if(c == 27) break;
    }

    return 0;
}
