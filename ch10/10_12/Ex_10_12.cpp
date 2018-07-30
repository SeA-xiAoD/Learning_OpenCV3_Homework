#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat origin_img = cv::imread("../faces.png");

    // a
    cv::Mat img1;
    cv::resize(origin_img, img1, cv::Size(origin_img.rows / 2, origin_img.cols / 2));
    cv::resize(img1, img1, cv::Size(img1.rows / 2, img1.cols / 2));
    cv::resize(img1, img1, cv::Size(img1.rows / 2, img1.cols / 2));
    cv::imshow("resize", img1);

    // b
    cv::Mat img2;
    cv::pyrDown(origin_img, img2);
    cv::pyrDown(img2, img2);
    cv::pyrDown(img2, img2);
    cv::imshow("pyrDown", img1);

    std::cout << img1.size << " " << img2.size << std::endl;
    cv::waitKey(0);

    return 0;
}
