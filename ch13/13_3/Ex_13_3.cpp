#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat hand_indoor_color = cv::imread("../HandIndoorColor.jpg");
    cv::Mat hand_outdoor_color = cv::imread("../HandOutdoorColor.jpg");
    cv::Mat hand_outdoor_sun_color = cv::imread("../HandOutdoorSunColor.jpg");
    cv::Mat fruit_color = cv::imread("../fruits.jpg");

    cv::Mat hist_indoor_color, hist_outdoor_color, hist_outdoor_sun_color, hist_fruit_color;

    float b_ranges[] = {0, 256}, g_ranges[] = {0, 256}, r_ranges[] = {0, 256};
    const float * ranges[] = {b_ranges, g_ranges, r_ranges};
    int ch[] = {0, 1, 2};

    // 16
    int hist_size_16[] = {16,16,16};
    cv::calcHist(&hand_indoor_color, 1, ch, cv::noArray(), hist_indoor_color, 3, hist_size_16, ranges);
    cv::normalize(hist_indoor_color, hist_indoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_outdoor_color, 1, ch, cv::noArray(), hist_outdoor_color, 3, hist_size_16, ranges);
    cv::normalize(hist_outdoor_color, hist_outdoor_color, 0, 1, cv::NORM_MINMAX);
    cv::calcHist(&hand_outdoor_sun_color, 1, ch, cv::noArray(), hist_outdoor_sun_color, 3, hist_size_16, ranges);
    cv::normalize(hist_outdoor_sun_color, hist_outdoor_sun_color, 0, 1, cv::NORM_MINMAX);
    cout << 1<< endl;
    cv::calcHist(&fruit_color, 1, ch, cv::noArray(), hist_fruit_color, 3, hist_size_16, ranges);
    cv::normalize(hist_fruit_color, hist_fruit_color, 0, 1, cv::NORM_MINMAX);


    // EMD
    vector<cv::Vec4f> sig_indoor_color, sig_outdoor_color, sig_outdoor_sun_color, sig_fruit_color;
    for(int i = 0; i < 16; i++ )
    {
        for(int j = 0; j < 16; j++ )
        {
            for(int k = 0; k < 16; k++)
            {
                sig_indoor_color.push_back(cv::Vec4f(hist_indoor_color.at<float>(i,j,k),(float)i,(float)j,(float)k));
                sig_outdoor_color.push_back(cv::Vec4f(hist_outdoor_color.at<float>(i,j,k),(float)i,(float)j,(float)k));
                sig_outdoor_sun_color.push_back(cv::Vec4f(hist_outdoor_sun_color.at<float>(i,j,k),(float)i,(float)j,(float)k));
                sig_fruit_color.push_back(cv::Vec4f(hist_fruit_color.at<float>(i,j,k),(float)i,(float)j,(float)k));
            }
        }
    }

    cv::Mat signature_indoor_color = cv::Mat(sig_indoor_color).reshape(1);
    cv::Mat signature_outdoor_color = cv::Mat(sig_outdoor_color).reshape(1);
    cv::Mat signature_outdoor_sun_color = cv::Mat(sig_outdoor_sun_color).reshape(1);
    cv::Mat signature_fruit_color = cv::Mat(sig_fruit_color).reshape(1);

    // a
    cout << "a:" << endl;
    cout << cv::EMD(signature_indoor_color, signature_outdoor_color, cv::DIST_L2) << endl;
    cout << cv::EMD(signature_indoor_color, signature_outdoor_sun_color, cv::DIST_L2) << endl;
    cout << cv::EMD(signature_outdoor_sun_color, signature_outdoor_color, cv::DIST_L2) << endl << endl;

    // b
    cout << "b:" << endl;
    cout << cv::EMD(signature_fruit_color, signature_indoor_color, cv::DIST_L2) << endl;
    cout << cv::EMD(signature_fruit_color, signature_outdoor_color, cv::DIST_L2) << endl;
    cout << cv::EMD(signature_fruit_color, signature_outdoor_sun_color, cv::DIST_L2) << endl;

    return 0;
}
