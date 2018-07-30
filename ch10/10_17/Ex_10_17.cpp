#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::imread("../faces.png");
    cv::Mat result, f_img, sep_result;

    origin_img.convertTo(f_img, CV_32FC3, 1.0/255);

    cv::Scharr(f_img, result, CV_32FC1, 1, 0);
    cv::imshow("Ex_10_17", result);
    cv::waitKey(0);

    cv::Mat row_filter, col_filter;
    row_filter = cv::Mat::zeros(1, 3, CV_32FC1);
    col_filter = cv::Mat::zeros(3, 1, CV_32FC1);

    row_filter.at<float>(0, 0) = -1;
    row_filter.at<float>(0, 1) = 0;
    row_filter.at<float>(0, 2) = 1;

    col_filter.at<float>(0, 0) = 3;
    col_filter.at<float>(1, 0) = 10;
    col_filter.at<float>(2, 0) = 3;

    cv::sepFilter2D(f_img, sep_result, CV_32FC3, row_filter, col_filter);
    cv::imshow("Sep Result", sep_result);
    cv::imshow("Result - Sep Result", cv::abs(result - sep_result));
    cv::waitKey(0);

    return 0;
}
