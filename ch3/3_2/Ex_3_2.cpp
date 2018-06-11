#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Matx33f m33(1, 2, 3, 4, 5, 6, 7, 8, 9);
	cv::Vec3f v3(1, 2, 3);
	std::cout << m33 * v3 << std::endl;
	return 0;
}