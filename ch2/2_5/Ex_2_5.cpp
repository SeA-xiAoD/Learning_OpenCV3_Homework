#include <opencv2/opencv.hpp>
#include <iostream>

int level = 2;

void onTrackerSlide(int pos, void*)
{
	level = pos;
	if(level <= 1)
	{
		level = 2;
	}
}

int main(int argc, char** argv)
{
	cv::namedWindow("Ex_2_5", cv::WINDOW_AUTOSIZE );
	cv::createTrackbar("D_level:", "Ex_2_5", &level, 8, onTrackerSlide);

	cv::VideoCapture capture;
	capture.open(0);

	if(!capture.isOpened())
	{
		std::cerr << "Camera is not opened!" << std::endl;
	}

	cv::Mat frame;

	while(1)
	{
		capture >> frame;
		for(int i = 2; i <= level; i++)
		{
			cv::pyrDown(frame, frame);
		}
		cv::imshow("Ex_2_5", frame);
		char c = cv::waitKey(33);
		if(c >= 27 ) break;
	}
	cv::destroyAllWindows();
	capture.release();
	return 0;
}