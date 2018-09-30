#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat hand_indoor_color = cv::imread("../HandIndoorColor.jpg");
    cv::Mat hand_outdoor_color = cv::imread("../HandOutdoorColor.jpg");
    cv::Mat hand_outdoor_sun_color = cv::imread("../HandOutdoorSunColor.jpg");

    cv::Mat hist_indoor_color, hist_outdoor_color, hist_outdoor_sun_color;

    float b_ranges[] = {0, 256}, g_ranges[] = {0, 256}, r_ranges[] = {0, 256};
    const float * ranges[] = {b_ranges, g_ranges, r_ranges};
    int ch[] = {0, 1, 2};

    // a
    cout << "a:" << endl << endl;

    // 2
    int hist_size_2[] = {2, 2, 2};
    cv::calcHist(&hand_outdoor_color, 1, ch, cv::noArray(), hist_outdoor_color, 3, hist_size_2, ranges);
    cv::normalize(hist_outdoor_color, hist_outdoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_outdoor_sun_color, 1, ch, cv::noArray(), hist_outdoor_sun_color, 3, hist_size_2, ranges);
    cv::normalize(hist_outdoor_sun_color, hist_outdoor_sun_color, 0, 1, cv::NORM_MINMAX);
    cout << "2 per dimention:" << endl;
    cout << "COMP_CORREL: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_CORREL) << endl;
    cout << "COMP_CHISQR_ALT: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_CHISQR_ALT) << endl;
    cout << "COMP_INTERSECT: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_INTERSECT) << endl;
    cout << "COMP_BHATTACHARYYA: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_BHATTACHARYYA) << endl << endl;

    // 16
    int hist_size_16[] = {16, 16, 16};
    cv::calcHist(&hand_outdoor_color, 1, ch, cv::noArray(), hist_outdoor_color, 3, hist_size_16, ranges);
    cv::normalize(hist_outdoor_color, hist_outdoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_outdoor_sun_color, 1, ch, cv::noArray(), hist_outdoor_sun_color, 3, hist_size_16, ranges);
    cv::normalize(hist_outdoor_sun_color, hist_outdoor_sun_color, 0, 1, cv::NORM_MINMAX);
    cout << "16 per dimention:" << endl;
    cout << "COMP_CORREL: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_CORREL) << endl;
    cout << "COMP_CHISQR_ALT: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_CHISQR_ALT) << endl;
    cout << "COMP_INTERSECT: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_INTERSECT) << endl;
    cout << "COMP_BHATTACHARYYA: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_BHATTACHARYYA) << endl << endl;

    // 256
    int hist_size_256[] = {256, 256, 256};
    cv::calcHist(&hand_outdoor_color, 1, ch, cv::noArray(), hist_outdoor_color, 3, hist_size_256, ranges);
    cv::normalize(hist_outdoor_color, hist_outdoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_outdoor_sun_color, 1, ch, cv::noArray(), hist_outdoor_sun_color, 3, hist_size_256, ranges);
    cv::normalize(hist_outdoor_sun_color, hist_outdoor_sun_color, 0, 1, cv::NORM_MINMAX);
    cout << "256 per dimention:" << endl;
    cout << "COMP_CORREL: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_CORREL) << endl;
    cout << "COMP_CHISQR_ALT: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_CHISQR_ALT) << endl;
    cout << "COMP_INTERSECT: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_INTERSECT) << endl;
    cout << "COMP_BHATTACHARYYA: " << cv::compareHist(hist_outdoor_color, hist_outdoor_sun_color, cv::HISTCMP_BHATTACHARYYA) << endl << endl;

    // b
    cout << "b:" << endl << endl;

    // 8
    int hist_size_8[] = {8, 8, 8};
    cv::calcHist(&hand_outdoor_color, 1, ch, cv::noArray(), hist_outdoor_color, 3, hist_size_8, ranges);
    cv::normalize(hist_outdoor_color, hist_outdoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_indoor_color, 1, ch, cv::noArray(), hist_indoor_color, 3, hist_size_8, ranges);
    cv::normalize(hist_indoor_color, hist_indoor_color, 0, 1, cv::NORM_MINMAX);
    cout << "8 per dimention:" << endl;
    cout << "COMP_CORREL: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_CORREL) << endl;
    cout << "COMP_CHISQR_ALT: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_CHISQR_ALT) << endl;
    cout << "COMP_INTERSECT: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_INTERSECT) << endl;
    cout << "COMP_BHATTACHARYYA: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_BHATTACHARYYA) << endl << endl;

    // 32
    int hist_size_32[] = {32, 32, 32};
    cv::calcHist(&hand_outdoor_color, 1, ch, cv::noArray(), hist_outdoor_color, 3, hist_size_32, ranges);
    cv::normalize(hist_outdoor_color, hist_outdoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_indoor_color, 1, ch, cv::noArray(), hist_indoor_color, 3, hist_size_32, ranges);
    cv::normalize(hist_indoor_color, hist_indoor_color, 0, 1, cv::NORM_MINMAX);
    cout << "32 per dimention:" << endl;
    cout << "COMP_CORREL: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_CORREL) << endl;
    cout << "COMP_CHISQR_ALT: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_CHISQR_ALT) << endl;
    cout << "COMP_INTERSECT: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_INTERSECT) << endl;
    cout << "COMP_BHATTACHARYYA: " << cv::compareHist(hist_outdoor_color, hist_indoor_color, cv::HISTCMP_BHATTACHARYYA) << endl << endl;

    return 0;
}
