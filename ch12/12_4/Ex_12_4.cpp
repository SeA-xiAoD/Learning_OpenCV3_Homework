#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../faces.png", cv::IMREAD_GRAYSCALE);
    cv::Mat img_32f = cv::Mat::zeros(img.rows, img.cols, CV_32FC1);
    img.convertTo(img_32f, CV_32FC1, 1.0/255, 0);

    cv::Mat gaussian_distribution = cv::Mat::zeros(img.rows, img.cols, CV_32FC1);
    cv::RNG rng = cv::theRNG();
    rng.fill(gaussian_distribution, cv::RNG::NORMAL, 0.5, 1);

    cv::Mat f_img, f_gaussian_distribution;
    cv::dct(img_32f, f_img);
    cv::dct(gaussian_distribution, f_gaussian_distribution);
    cv::imshow("Ex_12_4_f_img", f_img);
    cv::imshow("Ex_12_4_f_gaussian_distribution", f_gaussian_distribution);

    cv::Mat m, i_m;
    cv::mulSpectrums(f_img, f_gaussian_distribution, m, 0);
    cv::idct(m, i_m);

    double max, min;
    cv::minMaxLoc(i_m, &min, &max, NULL, NULL);
    cv::imshow("Ex_12_4_inverse_mul", (i_m - min)/(max - min));
    cv::waitKey(0);

    return 0;
}
