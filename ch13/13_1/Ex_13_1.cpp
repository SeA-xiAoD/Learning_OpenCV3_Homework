#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat img = cv::Mat::zeros(1000, 1, CV_32FC1);
    cv::RNG rng = cv::theRNG();
    rng.fill(img, cv::RNG::UNIFORM, 0.0, 1.0);

    cv::Mat hist;
    float value_range[] = {0.0, 1.0};
    const float* ranges[] = {value_range};
    int channel_size[] = {0};
    int hist_size[] = {10};
    cv::calcHist(&img, 1, channel_size, cv::noArray(), hist, 1, hist_size, ranges);

    cout << "Histgram:" << endl << hist << endl;

    return 0;
}
