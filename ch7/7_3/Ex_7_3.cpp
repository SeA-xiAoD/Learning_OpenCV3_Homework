#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    cv::RNG rng = cv::theRNG();
    cv::Mat m = cv::Mat::zeros(100, 1, CV_8UC3);
    vector<cv::Mat> m_channel;
    cv::split(m, m_channel);

    // a
    rng.fill(m_channel[0], cv::RNG::NORMAL, 64, 10);
    rng.fill(m_channel[1], cv::RNG::NORMAL, 192, 10);

    // b
    rng.fill(m_channel[2], cv::RNG::UNIFORM, 128, 2);

    // c
    cv::PCA pca0(m_channel[0], cv::noArray(), CV_PCA_DATA_AS_ROW, 2);
    cv::PCA pca1(m_channel[1], cv::noArray(), CV_PCA_DATA_AS_ROW, 2);
    cv::PCA pca2(m_channel[2], cv::noArray(), CV_PCA_DATA_AS_ROW, 2);

    m_channel[0] = pca0.project(m_channel[0]);
    m_channel[1] = pca1.project(m_channel[1]);
    m_channel[2] = pca2.project(m_channel[2]);
    cv::merge(m_channel, m);
    cout << m << endl;

    // d
    cout << cv::mean(m) << endl;

    return 0;
}
