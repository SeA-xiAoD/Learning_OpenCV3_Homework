#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../faces.png");

    // a
    cv::Mat smooth3, smooth5, smooth9, smooth11;
    cv::GaussianBlur(img, smooth3, cv::Size(3, 3), 0);
    cv::imshow("Smooth 3x3", smooth3);
    cv::GaussianBlur(img, smooth5, cv::Size(5, 5), 0);
    cv::imshow("Smooth 5x5", smooth5);
    cv::GaussianBlur(img, smooth9, cv::Size(9, 9), 0);
    cv::imshow("Smooth 9x9", smooth9);
    cv::GaussianBlur(img, smooth11, cv::Size(11, 11), 0);
    cv::imshow("Smooth 11x11", smooth11);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // b
    cv::GaussianBlur(smooth5, smooth5, cv::Size(5, 5), 0);
    cv::imshow("Smooth 5x5", smooth5);
    cv::imshow("Smooth 11x11", smooth11);
    cv::waitKey(0);

    return 0;
}
