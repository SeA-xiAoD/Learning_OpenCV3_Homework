#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat original_img = cv::imread("../faces.png");
    cv::Mat writing_img = original_img.clone(), mask(original_img.size(), CV_8UC1), repaired_img;

    // Inpaint
    cv::putText(writing_img, "TEST INPAINT", cv::Point(50, 500), CV_FONT_HERSHEY_PLAIN, 8.0, cv::Scalar(255, 255, 255), 2);
    cv::imshow("Ex_11_6_writing", writing_img);

    // Repair
    cv::putText(mask, "TEST INPAINT", cv::Point(50, 500), CV_FONT_HERSHEY_PLAIN, 8.0, cv::Scalar(255), 2);
    cv::inpaint(writing_img, mask, repaired_img, 3, cv::INPAINT_NS);
    cv::imshow("Ex_11_6_repaired", repaired_img);

    cv::waitKey(0);

    return 0;
}
