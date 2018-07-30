#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::Mat::zeros(100, 100, CV_8U);
    img.at<uchar>(49, 49) = 255;
    img.at<uchar>(49, 50) = 255;
    img.at<uchar>(50, 49) = 255;
    img.at<uchar>(50, 50) = 255;

    cv::Mat smooth5, smooth9;

    // a
    cv::GaussianBlur(img, smooth5, cv::Size(5, 5), 0);
    cv::imshow("Smooth 5x5", smooth5);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // b
    cv::GaussianBlur(img, smooth9, cv::Size(9, 9), 0);
    cv::imshow("Smooth 9x9", smooth9);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // c
    cv::GaussianBlur(smooth5, smooth5, cv::Size(5, 5), 0);
    cv::imshow("Smooth 5x5", smooth5);
    cv::imshow("Smooth 9x9", smooth9);
    cv::waitKey(0);

    return 0;
}
