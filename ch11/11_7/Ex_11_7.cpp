#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat original_img = cv::imread("../faces.png", cv::IMREAD_GRAYSCALE);
    cv::imshow("Ex_11_7_original", original_img);

    cv::Mat result_img;
    cv::equalizeHist(original_img, result_img);
    cv::imshow("Ex_11_7_result", result_img);

    cv::waitKey(0);

    return 0;
}
