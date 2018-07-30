#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../faces.png");

    // a
    cv::Mat smooth1, smooth2, smooth3;
    cv::GaussianBlur(img, smooth1, cv::Size(9, 9), 1, 1);
    cv::imshow("Smooth 1,1", smooth1);
    cv::GaussianBlur(img, smooth2, cv::Size(9, 9), 4, 4);
    cv::imshow("Smooth 4,4", smooth2);
    cv::GaussianBlur(img, smooth3, cv::Size(9, 9), 6, 6);
    cv::imshow("Smooth 6,6", smooth3);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // b
    cv::GaussianBlur(img, smooth1, cv::Size(9, 9), 1, 9);
    cv::imshow("Smooth 1,9", smooth1);
    cv::GaussianBlur(img, smooth2, cv::Size(9, 9), 9, 1);
    cv::imshow("Smooth 9,1", smooth2);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // c
    cv::GaussianBlur(smooth1, smooth1, cv::Size(9, 9), 9, 1);
    cv::imshow("Smooth 1,9 -> 9,1", smooth1);
    cv::GaussianBlur(smooth2, smooth2, cv::Size(9, 9), 1, 9);
    cv::imshow("Smooth 9,1 -> 1,9", smooth2);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
