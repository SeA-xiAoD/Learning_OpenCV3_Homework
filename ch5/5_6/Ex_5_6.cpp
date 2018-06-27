#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc, const char** argv )
{
    cv::Mat image = cv::imread("../faces.png");
    vector<cv::Mat> channels;
    cv::split(image, channels);

    // a
    cv::Mat green_image = channels[1];
    cv::namedWindow("Ex_5_6_a", cv::WINDOW_AUTOSIZE);
    cv::imshow("Ex_5_6_a", green_image);
    cv::waitKey(0);

    // b
    cv::Mat clone1 = green_image.clone(), clone2 = green_image.clone();

    // c
    double maximum, minimum;
    cout << 1 << endl;
    cv::minMaxLoc(green_image, &maximum, &minimum);
    cout << maximum << " " <<  minimum << endl;

    // d
    unsigned char thresh = (unsigned char)((maximum - minimum)/2.0);
    clone1 = thresh;

    // e
    clone2 = 0;cv::compare(green_image, clone1, clone2, cv::CMP_GE);

    // f
    cv::subtract(green_image, thresh/2, green_image, clone2);
    cv::namedWindow("Ex_5_6_f", cv::WINDOW_AUTOSIZE);
    cv::imshow("Ex_5_6_f", green_image);
    cv::waitKey(0);

    return 0;
}