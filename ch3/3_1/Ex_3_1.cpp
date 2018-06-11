#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	// a
    float f = -2.5;
    f = cv::abs(f);
	std::cout << f << std::endl;
	
	// b
	f = cvRound(f);
	std::cout << f << std::endl;
	
	// c
	f = cvflann::rand();
	std::cout << f << std::endl;
    
	// d
	cv::Point2f p1(1.0, 2.0);
	cv::Point p2 = static_cast<cv::Point>(p1);
	cv::Point2f p3 = static_cast<cv::Point2f>(p2);
	return 0;
}