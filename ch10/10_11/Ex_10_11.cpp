#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::imread("../faces.png");
    cv::Mat gray_img;
    cv::cvtColor(origin_img, gray_img, CV_BGR2GRAY);
    cv::cvtColor(gray_img, gray_img, CV_GRAY2BGR);

    // a
    cv::Mat top_hat;
    cv::morphologyEx(gray_img, top_hat, cv::MORPH_TOPHAT, cv::Mat());
    cv::imshow("Top Hat", top_hat);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // b
    cv::Mat mask;
    cv::cvtColor(top_hat, mask, CV_BGR2GRAY);
    cv::imshow("Mask", mask);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // c
    gray_img.copyTo(origin_img, mask);
    cv::imshow("Copied Original Image", mask);
    cv::waitKey(0);

    return 0;
}
