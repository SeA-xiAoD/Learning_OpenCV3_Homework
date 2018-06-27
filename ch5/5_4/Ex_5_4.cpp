#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, const char** argv )
{
    cv::Mat m(210, 210, CV_8UC1);
    m = 0;
    for(int i = 1; i < 11; i++)
    {
        cv::Mat mask(210 - 20*i, 210 - 20*i, CV_8UC1);
        cv::Mat ROI(m(cv::Rect(i*10, i*10, 210 - 20*i, 210 - 20*i)));
        mask = 1;
        if(i < 10)
            mask.rowRange(10, 210 - 20*i - 10).colRange(10, 210 - 20*i - 10) = 0;
        ROI.setTo((i + 1)*20, mask);
    }
    cv::namedWindow("Ex_5_4", cv::WINDOW_AUTOSIZE);
    cv::imshow("Ex_5_4", m);
    cv::waitKey(0);
    return 0;
}