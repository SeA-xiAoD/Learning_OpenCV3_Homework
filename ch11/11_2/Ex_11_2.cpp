#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat img = cv::Mat(800, 800, CV_8U);
    cv::rectangle(img, cv::Rect(199, 199, 400, 400), cv::Scalar(255), 1);
    cv::imshow("Ex_11_2", img);

    cv::Mat on_corner, inside_edge, outside_edge;

    // a
    cv::logPolar(img, on_corner, cv::Point(199, 199), 50, cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS);
    cv::imshow("Ex_11_2_on_corner", on_corner);

    // b
    cv::logPolar(img, inside_edge, cv::Point(300, 300), 50, cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS);
    cv::imshow("Ex_11_2_inside_edge", inside_edge);

    // c
    cv::logPolar(img, outside_edge, cv::Point(100, 100), 50, cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS);
    cv::imshow("Ex_11_2_outside_edge", outside_edge);

    cv::waitKey(0);

    return 0;
}
