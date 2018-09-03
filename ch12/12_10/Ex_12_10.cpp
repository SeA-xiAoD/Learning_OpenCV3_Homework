#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../messi5.jpg");
    cv::Mat mean_shift;

    cv::pyrMeanShiftFiltering(img, mean_shift, 20, 40 ,2);

    // segment1
    cv::floodFill(mean_shift, cv::Point(0, img.rows - 1), cv::Scalar(0,0,255), 0,
                  cv::Scalar(25,25,25), cv::Scalar(25,25,25), cv::FLOODFILL_FIXED_RANGE);

    // segment2
    cv::floodFill(mean_shift, cv::Point(0, 0), cv::Scalar(255,0,0), 0,
                  cv::Scalar(50,50,50), cv::Scalar(50,50,50), cv::FLOODFILL_FIXED_RANGE);


    cv::imshow("Ex_12_10_img", img);
    cv::imshow("Ex_12_10_mask", mean_shift);

    cv::waitKey(0);

    return 0;
}
