#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat m33 = cv::Mat::eye(3, 3, CV_32F);
	cv::Vec3f v3(1, 2, 3);
	
	// b
	// error: invalid operands to binary expression ('cv::Mat' and 'cv::Vec3f'(aka 'Vec<float, 3>'))
	//std::cout << m33 * v3;
	
	// c
	cv::Mat v3_m(v3);
	std::cout << m33 * v3_m << std::endl;
	return 0;
}