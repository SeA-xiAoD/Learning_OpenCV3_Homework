#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::VideoCapture capture;
	capture.open(0);

	double fps = capture.get(cv::CAP_PROP_FPS);
	cv::Size size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH) / 2, (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT) / 2);
	
	cv::VideoWriter writer;
	writer.open("output.avi", CV_FOURCC('M','J','P','G'), fps, size);

	if(!capture.isOpened())
	{
		std::cerr << "Camera is not opened!" << std::endl;
	}

	cv::Mat frame, frame_after_down;

	while(1)
	{
		capture >> frame;
		cv::pyrDown(frame, frame_after_down);
		writer << frame_after_down;
		char c = cv::waitKey(33);
		if(c >= 27 ) break;
	}
    capture.release();
    writer.release();
	return 0;
}