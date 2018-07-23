#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat bgr_frame, gray_frame, canny_frame;
    cv::VideoCapture capture;
    capture.open("../tree.avi");
    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::namedWindow("BGR Frame", CV_WINDOW_AUTOSIZE);
    cv::namedWindow("Gray Frame", CV_WINDOW_AUTOSIZE);
    cv::namedWindow("Canny Frame", CV_WINDOW_AUTOSIZE);

    capture >> bgr_frame;
    while(!bgr_frame.empty())
    {
        cv::cvtColor(bgr_frame, gray_frame, CV_BGR2GRAY);
        cv::Canny(gray_frame, canny_frame, 3, 4);
        cv::putText(bgr_frame, "BRG frame", cv::Point(20, 20), CV_FONT_HERSHEY_PLAIN, 1.5, cv::Scalar(0, 0, 255), 2);
        cv::imshow("BGR Frame", bgr_frame);
        cv::putText(gray_frame, "Gray frame", cv::Point(20, 20), CV_FONT_HERSHEY_PLAIN, 1.5, cv::Scalar(0, 0, 0), 2);
        cv::imshow("Gray Frame", gray_frame);
        cv::putText(canny_frame, "Canny frame", cv::Point(20, 20), CV_FONT_HERSHEY_PLAIN, 1.5, cv::Scalar(0, 0, 0), 2);
        cv::imshow("Canny Frame", canny_frame);
        char c = static_cast<char>(cv::waitKey(1000/fps));
        if(c == 27) break;
        capture >> bgr_frame;
    }

    return 0;
}
