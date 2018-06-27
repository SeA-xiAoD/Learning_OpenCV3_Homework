#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, const char** argv )
{
    cv::Mat m = cv::imread("../faces.png");
    cv::Mat ROI1 = m(cv::Rect(5, 10, 20, 30));
    cv::Mat ROI2 = m(cv::Rect(50, 60, 20, 30));
    cv::bitwise_not(ROI1, ROI1);
    cv::bitwise_not(ROI2, ROI2);
    cv::namedWindow("Ex_5_5", cv::WINDOW_AUTOSIZE);
    cv::imshow("Ex_5_5", m);
    cv::waitKey(0);
    return 0;
}