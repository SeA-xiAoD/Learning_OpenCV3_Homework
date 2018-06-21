#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

void help()
{
	cout << "Original and integral image. Press 'ESC' to quit." << endl;
}

const int display_height = 200;
const int display_width = 100;

int main( int argc, char** argv) 
{
	// init numbers and display
	help();
	cv::Mat1b original_image(display_height, display_width);
	cv::Mat1f integral_image(display_height, display_width);
	cv::RNG rng(0);
	rng.fill(original_image, cv::RNG::UNIFORM, 0, 255);
	integral_image = 0;

	cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Original Image",original_image);

	for(int i = 0; i < display_height ; i++)
	{
		integral_image.at<float>(i, 0) = cv::sum(original_image.rowRange(0, i + 1).colRange(0, 1))[0];
	}
    for(int i = 0; i < display_width ; i++)
	{
		integral_image.at<float>(0, i) = cv::sum(original_image.rowRange(0, 1).colRange(0, i + 1))[0];
	}
	for(int i = 1; i < display_height; i++)
	{
		for(int j = 1; j < display_width; j++)
		{
			integral_image.at<float>(i, j) = (float)original_image.at<uchar>(i, j) + integral_image.at<float>(i - 1, j) + integral_image.at<float>(i, j - 1) - integral_image.at<float>(i - 1, j - 1);
		}
	}
	integral_image /= integral_image.at<float>(display_height - 1, display_width - 1);

	cv::namedWindow("Integral Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Integral Image",integral_image);

	cv::waitKey(0);
	
	return 0;
}