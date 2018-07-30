#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::imread("../faces.png");
    cv::cvtColor(origin_img, origin_img, CV_BGR2GRAY);
    cv::Mat img, kernel, f_img;

    origin_img.convertTo(f_img, CV_32FC3, 1.0/255);

    kernel = cv::Mat::zeros(3, 2, CV_32FC1);

    kernel.at<float>(0, 0) = 0;
    kernel.at<float>(0, 1) = 0;
    kernel.at<float>(0, 2) = 0.33333;

    kernel.at<float>(1, 0) = 0;
    kernel.at<float>(1, 1) = 0.33333;
    kernel.at<float>(1, 2) = 0.33333;

    cv::filter2D(f_img, img, CV_32FC1, kernel);
    cv::threshold(img, img, 0.99, 1, CV_THRESH_BINARY);

    cv::imshow("Ex_10_15", img);
    cv::waitKey(0);

    return 0;
}
