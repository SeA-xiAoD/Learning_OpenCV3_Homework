#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../bicycle.jpg", cv::IMREAD_GRAYSCALE);
    img.convertTo(img, CV_32FC1, 1.0/255, 0);

    cv::Mat integral;
    cv::integral(img, integral);
    cv::imshow("Ex_12_5", integral / integral.at<double>(integral.rows - 1, integral.cols - 1));

    cv::Mat edges = cv::Mat::zeros(img.rows, img.cols, CV_64FC1);
    for(int i = 0; i < integral.rows - 1; i++)
    {
        for(int j = 0; j < integral.cols - 2; j++)
        {
            // compute grad of (i,j+2) -> (i,j)
            double grad = integral.at<double>(i + 1, j + 2) - integral.at<double>(i + 1, j) - integral.at<double>(i, j + 2) + integral.at<double>(i, j);
            if(grad < 0.1)
                edges.at<double>(i, j) = 1.0;
        }
    }
    cv::imshow("edges", edges);
    cv::waitKey(0);

    return 0;
}

