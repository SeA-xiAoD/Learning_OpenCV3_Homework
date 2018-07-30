#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::Mat::zeros(500, 500, CV_32FC1);
    cv::Mat result;

    // a
    int now_r = 3;
    for(int i = 0; i < 200; i++)
    {
        cv::circle(img, cv::Point(249,249), now_r, cv::Scalar(1));
        now_r += 3;
    }
    cv::Scharr(img, result, CV_32FC1, 1, 0);
    cv::imshow("Ex_10_18_3", result);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // b
    img = cv::Mat::zeros(500, 500, CV_32FC1);
    now_r = 5;
    for(int i = 0; i < 200; i++)
    {
        cv::circle(img, cv::Point(249,249), now_r, cv::Scalar(1));
        now_r += 5;
    }
    cv::Scharr(img, result, CV_32FC1, 1, 0);
    cv::imshow("Ex_10_18_5_x", result);
    img = cv::Mat::zeros(500, 500, CV_32FC1);
    now_r = 5;
    for(int i = 0; i < 200; i++)
    {
        cv::circle(img, cv::Point(249,249), now_r, cv::Scalar(1));
        now_r += 5;
    }
    cv::Scharr(img, result, CV_32FC1, 0, 1);
    cv::imshow("Ex_10_18_5_y", result);
    cv::waitKey(0);
    cv::destroyAllWindows();

    img = cv::Mat::zeros(500, 500, CV_32FC1);
    now_r = 9;
    for(int i = 0; i < 200; i++)
    {
        cv::circle(img, cv::Point(249,249), now_r, cv::Scalar(1));
        now_r += 9;
    }
    cv::Scharr(img, result, CV_32FC1, 1, 0);
    cv::imshow("Ex_10_18_9_x", result);
    img = cv::Mat::zeros(500, 500, CV_32FC1);
    now_r = 9;
    for(int i = 0; i < 200; i++)
    {
        cv::circle(img, cv::Point(249,249), now_r, cv::Scalar(1));
        now_r += 9;
    }
    cv::Scharr(img, result, CV_32FC1, 0, 1);
    cv::imshow("Ex_10_18_9_y", result);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // d
    img = cv::Mat::zeros(500, 500, CV_32FC1);
    now_r = 13;
    for(int i = 0; i < 200; i++)
    {
        cv::circle(img, cv::Point(249,249), now_r, cv::Scalar(1));
        now_r += 13;
    }
    cv::Scharr(img, result, CV_32FC1, 1, 0);
    cv::imshow("Ex_10_18_13_x", result);
    img = cv::Mat::zeros(500, 500, CV_32FC1);
    now_r = 13;
    for(int i = 0; i < 200; i++)
    {
        cv::circle(img, cv::Point(249,249), now_r, cv::Scalar(1));
        now_r += 13;
    }
    cv::Scharr(img, result, CV_32FC1, 0, 1);
    cv::imshow("Ex_10_18_13_y", result);
    cv::waitKey(0);

    return 0;
}
