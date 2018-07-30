#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::imread("../faces.png");
    cv::Mat img;

    // Threshold_binary
    cv::threshold(origin_img, img, 128, 255, cv::THRESH_BINARY);
    cv::imshow("Threshold_binary", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_binary_inv
    cv::threshold(origin_img, img, 128, 255, cv::THRESH_BINARY_INV);
    cv::imshow("Threshold_binary_inv", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_trunc
    cv::threshold(origin_img, img, 128, 255, cv::THRESH_TRUNC);
    cv::imshow("Threshold_trunc", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_tozero
    cv::threshold(origin_img, img, 128, 255, cv::THRESH_TOZERO);
    cv::imshow("Threshold_tozero", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_tozero_inv
    cv::threshold(origin_img, img, 128, 255, cv::THRESH_TOZERO_INV);
    cv::imshow("Threshold_tozero_inv", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // a
    cv::Mat gray_img;
    cv::cvtColor(origin_img, gray_img, CV_BGR2GRAY);

    // Threshold_binary
    cv::adaptiveThreshold(gray_img, img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 5, 5);
    cv::imshow("Threshold_binary_a", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_binary_inv
    cv::adaptiveThreshold(gray_img, img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 5, 5);
    cv::imshow("Threshold_binary_inv_a", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // b

    // Threshold_binary
    cv::adaptiveThreshold(gray_img, img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 5, 0);
    cv::imshow("Threshold_binary_a", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_binary_inv
    cv::adaptiveThreshold(gray_img, img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 5, 0);
    cv::imshow("Threshold_binary_inv_a", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_binary
    cv::adaptiveThreshold(gray_img, img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 5, -5);
    cv::imshow("Threshold_binary_a", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Threshold_binary_inv
    cv::adaptiveThreshold(gray_img, img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 5, -5);
    cv::imshow("Threshold_binary_inv_a", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
