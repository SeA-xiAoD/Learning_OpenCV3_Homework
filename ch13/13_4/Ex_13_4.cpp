#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat hand_indoor_color = cv::imread("../HandIndoorColor.jpg");
    cv::Mat hand_outdoor_color = cv::imread("../HandOutdoorColor.jpg");
    cv::Mat hand_outdoor_sun_color = cv::imread("../HandOutdoorSunColor.jpg");

    cv::cvtColor(hand_indoor_color, hand_indoor_color, cv::COLOR_BGR2HSV);
    cv::cvtColor(hand_outdoor_color, hand_outdoor_color, cv::COLOR_BGR2HSV);
    cv::cvtColor(hand_outdoor_sun_color, hand_outdoor_sun_color, cv::COLOR_BGR2HSV);

    cv::Mat hist_indoor_color, hist_outdoor_color, hist_outdoor_sun_color;

    float v_ranges[] = {0, 256};
    const float * ranges[] = {v_ranges};
    int ch[] = {2};

    int hist_size[] = {16};
    cv::calcHist(&hand_indoor_color, 1, ch, cv::noArray(), hist_indoor_color, 1, hist_size, ranges);
    cv::normalize(hist_indoor_color, hist_indoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_outdoor_color, 1, ch, cv::noArray(), hist_outdoor_color, 1, hist_size, ranges);
    cv::normalize(hist_outdoor_color, hist_outdoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_outdoor_sun_color, 1, ch, cv::noArray(), hist_outdoor_sun_color, 1, hist_size, ranges);
    cv::normalize(hist_outdoor_sun_color, hist_outdoor_sun_color, 0, 1, cv::NORM_MINMAX);


    float score_indoor_color = 0, score_outdoor_color = 0, score_outdoor_sun_color = 0;
    for(int i = 0; i < 16; i++)
    {
        score_indoor_color += i * hist_indoor_color.at<float>(i);
        score_outdoor_color += i * hist_outdoor_color.at<float>(i);
        score_outdoor_sun_color += i * hist_outdoor_sun_color.at<float>(i);
    }

    cout << "The value will be smaller if the brightness is lower:" << endl << endl;
    cout << "Indoor: " << score_indoor_color << endl
         << "Outdoor: " << score_outdoor_color << endl
         << "Outdoor_sun: " << score_outdoor_sun_color << endl;

    return 0;
}
