#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, const char** argv )
{
    cv::Mat m(100, 100, CV_8UC3);
    m = 0;
    cv::Scalar color(255, 0, 0);
    cv::circle(m, cv::Point(50, 50), 20, color);
    cv::namedWindow("Ex_5_1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Ex_5_1", m);
    cv::waitKey(0);
    return 0;
}