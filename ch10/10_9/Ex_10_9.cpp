#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat src1 = cv::imread("../20180729_151141.jpg", cv::IMREAD_GRAYSCALE), src2 = cv::imread("../20180729_151156.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat src_colorful = cv::imread("../20180729_151156.jpg");
    cv::resize(src1, src1, cv::Size(500, 500));
    cv::resize(src2, src2, cv::Size(500, 500));
    cv::resize(src_colorful, src_colorful, cv::Size(500, 500));

    // 5_a
    cv::Mat diff;
    diff = cv::abs(src1 - src2);
    cv::imshow("Ex_10_5_diff", diff);

    // 5_b
    cv::Mat bi_th;
    cv::threshold(diff, bi_th, 75, 255, cv::THRESH_BINARY);
    cv::imshow("Ex_10_5_binary_threshold", bi_th);

    // 5_c
    cv::Mat mop_open;
    cv::morphologyEx(bi_th, mop_open, cv::MORPH_OPEN, cv::Mat());
    cv::imshow("Ex_10_5_mop_open", mop_open);

    // 5_d
    cv::Mat erosion, outline;
    cv::erode(mop_open, erosion, cv::Mat());
    outline = mop_open ^ erosion;
    cv::imshow("Ex_10_5_outline", outline);


    // 9
    cv::Mat test_mug;
    src_colorful.copyTo(test_mug, mop_open);
    cv::imshow("Ex_10_9", test_mug);
    cv::waitKey(0);

    return 0;
}
