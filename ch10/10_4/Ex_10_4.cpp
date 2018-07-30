#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat src1 = cv::imread("../20180729_144022.jpg"), src2 = cv::imread("../20180729_144025.jpg");
    cv::resize(src1, src1, cv::Size(500, 500));
    cv::resize(src2, src2, cv::Size(500, 500));

    // a
    cv::Mat diff12;
    diff12 = cv::abs(src1 - src2);
    cv::imshow("Ex_10_4_diff12", diff12);

    // b
    cv::Mat cleandiff;
    cv::erode(diff12, cleandiff, cv::Mat());
    cv::dilate(cleandiff, cleandiff, cv::Mat());
    cv::imshow("Ex_10_4_cleandiff", cleandiff);

    // c
    cv::Mat dirtydiff;
    cv::dilate(diff12, dirtydiff, cv::Mat());
    cv::erode(dirtydiff, dirtydiff, cv::Mat());
    cv::imshow("Ex_10_4_dirtydiff", dirtydiff);
    cv::waitKey(0);

    return 0;
}
