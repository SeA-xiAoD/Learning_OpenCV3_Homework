#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::Mat::zeros(100, 100, CV_8UC1);
    img.rowRange(40, 60).colRange(40, 60) = 255;

    double r = sqrt(10*10 + 10*10);
    double angle = 30.0;

    cv::Point2f srcTri[] = {
            cv::Point2f(50 + cos(45.0 / 180.0 * 3.1415926) * r, 50 - sin(45.0 / 180.0 * 3.1415926) * r), // top right
            cv::Point2f(50 + cos(-45.0 / 180.0 * 3.1415926) * r, 50 - sin(-45.0 / 180.0 * 3.1415926) * r), // bottom right
            cv::Point2f(50 + cos(135.0 / 180.0 * 3.1415926) * r, 50 - sin(135.0 / 180.0 * 3.1415926) * r), // top left
    };

    cv::Point2f dstTri[] = {
            cv::Point2f(50 + cos((45.0 + angle) / 180.0 * 3.1415926) * r, 50 - sin((45.0 + angle) / 180.0 * 3.1415926) * r), // top right
            cv::Point2f(50 + cos((-45.0 + angle) / 180.0 * 3.1415926) * r, 50 - sin((-45.0 + angle) / 180.0 * 3.1415926) * r), // bottom right
            cv::Point2f(50 + cos((135.0 + angle) / 180.0 * 3.1415926) * r, 50 - sin((135.0 + angle) / 180.0 * 3.1415926) * r), // top left
    };
    cv::Mat tran_mat = cv::getAffineTransform(srcTri, dstTri);
    cv::warpAffine(img, img, tran_mat, img.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar());

    cv::distanceTransform(img, img, cv::DIST_L2, 3);

    double max_pixel;
    cv::minMaxLoc(img, nullptr, &max_pixel, 0, 0);
    cv::imshow("Ex_12_11", img / max_pixel);

    cv::waitKey(0);

    return 0;
}
