#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat img = cv::imread("../pupil.jpeg");
    cv::Mat laplacian_img;

    cv::Laplacian(img, laplacian_img, CV_8UC3);
    cv::Laplacian(laplacian_img, laplacian_img, CV_8UC3);
    cv::imshow("Ex_11_1_Laplacian", laplacian_img);

    cv::logPolar(laplacian_img, laplacian_img, cv::Point2f(laplacian_img.cols*0.5, laplacian_img.rows*0.5), 100, cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS);
    cv::imshow("Ex_11_1_logPolar", laplacian_img);

    cv::waitKey(0);

    return 0;
}
