#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat img = cv::Mat(1000, 1000, CV_8U);

    // large
    cv::rectangle(img, cv::Rect(199, 199, 600, 600), cv::Scalar(255), 1);

    // small
    cv::rectangle(img, cv::Rect(299, 299, 400, 400), cv::Scalar(255), 1);

    // large rotated
    cv::RotatedRect r_large(cv::Point(499, 499), cv::Size(600, 600), 45);
    cv::Point2f r_large_point[4];
    r_large.points(r_large_point);
    for(int i = 0; i < 4; i++)
    {
        cv::line(img, r_large_point[i], r_large_point[(i + 1)%4], cv::Scalar(255));
    }

    // small rotated
    cv::RotatedRect s_large(cv::Point(499, 499), cv::Size(400, 400), 45);
    cv::Point2f s_large_point[4];
    s_large.points(s_large_point);
    for(int i = 0; i < 4; i++)
    {
        cv::line(img, s_large_point[i], s_large_point[(i + 1)%4], cv::Scalar(255));
    }

    cv::imshow("Ex_11_4", img);

    cv::Mat logPolar;
    cv::logPolar(img, logPolar, cv::Point(499, 499), 100, cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS);
    cv::imshow("Ex_11_4_logPolar", logPolar);

    cv::waitKey(0);

    return 0;
}
