#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../bicycle.jpg", cv::IMREAD_GRAYSCALE);
    vector<cv::Vec2f> lines;
    vector<cv::Vec3f> circles;

    // line
    cv::Mat line_img = img.clone();
    cv::HoughLines(img, lines, 1, CV_PI/180, 1000);
    for(int i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        double a = cos(theta), b = sin(theta);
        double x0 = a * theta, y0 = b *rho;
        cv::Point p1(cvRound(x0 + 1000 * -b), y0 + 1000 * a);
        cv::Point p2(cvRound(x0 - 1000 * -b), y0 - 1000 * a);
        cv::line(line_img, p1, p2, cv::Scalar(255));
    }
    cv::imshow("Ex_12_2_line", line_img);
    cv::waitKey(0);

    // circle
    cv::Mat circle_img = img.clone();
    cv::HoughCircles(img, circles, cv::HOUGH_GRADIENT, 20, img.cols/10);
    for(int i = 0; i < circles.size(); i++)
    {
        cv::Point p(cvRound(circles[i][0]), cvRound(circles[i][1]));
        cv::circle(circle_img, p, cvRound(circles[i][2]), cv::Scalar(255));
    }
    cv::imshow("Ex_12_2_circle", circle_img);
    cv::waitKey(0);

    return 0;
}
