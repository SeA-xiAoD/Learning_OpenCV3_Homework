#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::RNG rng = cv::theRNG();
    // a
    cv::Mat m1 = cv::Mat::zeros(20, 1, CV_32F);
    rng.fill(m1, cv::RNG::UNIFORM, 0.0, 1.0);
    cout << "a:\n" << m1 << endl << endl;

    // b
    rng.fill(m1, cv::RNG::NORMAL, 0.0, 1.0);
    cout << "b:\n" << m1 << endl << endl;

    // c
    cv::Mat m2 = cv::Mat::zeros(20, 1, CV_8UC1);
    rng.fill(m2, cv::RNG::UNIFORM, 0, 255);
    cout << "c:\n" << m2 << endl << endl;

    // d
    cv::Mat m3 = cv::Mat::zeros(20, 1, CV_8UC3);
    rng.fill(m3, cv::RNG::UNIFORM, 0, 255);
    cout << "d:\n" << m3 << endl << endl;

    return 0;
}
