#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::imread("../faces.png");
    cv::Mat img, gray_img, edge;

    // pyrMeanShiftFiltering
    cv::pyrMeanShiftFiltering(origin_img, img, 1.0, 1.0);

    // retrieve edge
    cv::cvtColor(origin_img, gray_img, CV_BGR2GRAY);
    cv::Sobel(gray_img, edge, CV_8UC1, 2, 1);

    // combine
    origin_img.copyTo(img, edge);
    cv::imshow("Ex_10_14", img);
    cv::waitKey(0);

    return 0;
}