#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::Mat::zeros(500, 500, CV_32FC1);
    cv::line(origin_img, cv::Point(0,0), cv::Point(499,499), cv::Scalar(1.0,1.0,1.0), 1);
    cv::Mat dx, dy, mag, angle = cv::Mat::zeros(500, 500, CV_32FC1);

    // a
    cv::Sobel(origin_img, dx, CV_32F, 1, 0, 3);
    cv::Sobel(origin_img, dy, CV_32F, 0, 1, 3);
    cv::pow(dx, 2, dx);
    cv::pow(dy, 2, dy);
    cv::sqrt(dx + dy, mag);
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            angle.at<float>(i, j) = cv::fastAtan2(dy.at<float>(i, j), dx.at<float>(i, j));
        }
    }
    cv::imshow("Ex_10_19_3x3_mag", mag);
    cv::imshow("Ex_10_19_3x3_angle", angle);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // b
    cv::Sobel(origin_img, dx, CV_32F, 1, 0, 5);
    cv::Sobel(origin_img, dy, CV_32F, 0, 1, 5);
    cv::pow(dx, 2, dx);
    cv::pow(dy, 2, dy);
    cv::sqrt(dx + dy, mag);
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            angle.at<float>(i, j) = cv::fastAtan2(dy.at<float>(i, j), dx.at<float>(i, j));
        }
    }
    cv::imshow("Ex_10_19_5x5_mag", mag);
    cv::imshow("Ex_10_19_5x5_angle", angle);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // c
    cv::Sobel(origin_img, dx, CV_32F, 1, 0, 9);
    cv::Sobel(origin_img, dy, CV_32F, 0, 1, 9);
    cv::pow(dx, 2, dx);
    cv::pow(dy, 2, dy);
    cv::sqrt(dx + dy, mag);
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            angle.at<float>(i, j) = cv::fastAtan2(dy.at<float>(i, j), dx.at<float>(i, j));
        }
    }
    cv::imshow("Ex_10_19_9x9_mag", mag);
    cv::imshow("Ex_10_19_9x9_angle", angle);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
