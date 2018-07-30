#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::RNG rng = cv::theRNG();
    cv::Mat img = cv::Mat::zeros(500, 500, CV_32FC1);
    rng.fill(img, cv::RNG::NORMAL, 0, 3);

    cv::line(img, cv::Point(0, 249), cv::Point(499, 249), cv::Scalar(255, 255, 255));
    cv::line(img, cv::Point(0, 250), cv::Point(499, 250), cv::Scalar(255, 255, 255));
    cv::line(img, cv::Point(249, 0), cv::Point(249, 499), cv::Scalar(255, 255, 255));
    cv::line(img, cv::Point(250, 0), cv::Point(250, 499), cv::Scalar(255, 255, 255));

    cv::Mat result;
    cv::bilateralFilter(img, result, 5, 10, 2.5);

    cv::imshow("Ex_10_10", result);
    cv::waitKey(0);

    return 0;
}
