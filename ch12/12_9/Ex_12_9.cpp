#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../messi5.jpg");
    cv::Mat fgd_mask = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
    cv::Mat bgd_mask = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);

    cv::Mat bgdModel, fgdModel;
    cv::Rect rct = cv::Rect(50,50,450,290);

    cv::grabCut(img, fgd_mask, rct, bgdModel, fgdModel, 10, cv::GC_INIT_WITH_RECT);

    // if mask is equal to GC_PR_FGD, set to 255
    cv::compare(fgd_mask, cv::GC_PR_FGD, fgd_mask, cv::CMP_EQ);
    // compute bgd_mask
    bgd_mask = 255 ^ fgd_mask;

    cv::Mat for_inpaint = cv::Mat::zeros(img.rows, img.cols, CV_8UC3);
    img.copyTo(for_inpaint, bgd_mask);
    cv::inpaint(for_inpaint, fgd_mask, for_inpaint, 3, cv::INPAINT_NS);

    cv::imshow("Ex_12_9_img", img);
    cv::imshow("Ex_12_9_inpaint", for_inpaint);

    cv::waitKey(0);

    return 0;
}
