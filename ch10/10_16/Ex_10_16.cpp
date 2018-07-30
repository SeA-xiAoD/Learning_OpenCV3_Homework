#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::imread("../faces.png");
    cv::Mat img, kernel, f_img;

    // convert origin image to float
    origin_img.convertTo(f_img, CV_32FC3, 1.0/255);

    kernel = cv::Mat::zeros(3, 3, CV_32FC1);

    kernel.at<float>(0, 0) = 1.0/16;
    kernel.at<float>(0, 1) = 2.0/16;
    kernel.at<float>(0, 2) = 1.0/16;

    kernel.at<float>(1, 0) = 2.0/16;
    kernel.at<float>(1, 1) = 4.0/16;
    kernel.at<float>(1, 2) = 2.0/16;

    kernel.at<float>(2, 0) = 1.0/16;
    kernel.at<float>(2, 1) = 2.0/16;
    kernel.at<float>(2, 2) = 1.0/16;


    // a
    cv::filter2D(f_img, img, CV_32FC1, kernel);
    cv::imshow("Ex_10_16", img);
    cv::waitKey(0);

    // b
    cv::Mat order1, order2;
    cv::Mat row_filter, col_filter;
    row_filter = cv::Mat::zeros(1, 3, CV_32FC1);
    col_filter = cv::Mat::zeros(3, 1, CV_32FC1);

    row_filter.at<float>(0, 0) = 1.0/4;
    row_filter.at<float>(0, 1) = 2.0/4;
    row_filter.at<float>(0, 2) = 1.0/4;

    col_filter.at<float>(0, 0) = 1.0/4;
    col_filter.at<float>(1, 0) = 2.0/4;
    col_filter.at<float>(2, 0) = 1.0/4;

    cv::filter2D(f_img, order1, CV_32FC1, row_filter);
    cv::filter2D(order1, order1, CV_32FC1, col_filter);
    cv::imshow("Row -> Col", order1);

    cv::filter2D(f_img, order2, CV_32FC1, col_filter);
    cv::filter2D(order2, order2, CV_32FC1, row_filter);
    cv::imshow("Col -> Row", order2);

    cv::waitKey(0);

    // c
    cv::imshow("3 x 3 - (1 x 1 -> 1 x 1)", cv::abs(img - order1));
    cv::imshow("Order1 - Order2", cv::abs(order1 - order2));
    cv::waitKey(0);

    return 0;
}
