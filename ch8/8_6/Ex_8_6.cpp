#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace std;

// using to record the spot the user will type.
cv::Point p;

// get text from keyboard
string receive_text()
{
    string text;
    while (1)
    {
        char c = static_cast<char>(cv::waitKey(0));
        if(c == 27)
            return NULL;
        else if(c == '\r')
            return text;
        else
            text += c;
    }
}

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
    cv::Mat& img = *(cv::Mat*) param;
    string text;
    switch (event)
    {
        case CV_EVENT_LBUTTONDOWN:
        {
            text = receive_text();
            cout << text << endl;
            cv::putText(img, text, cv::Point(x, y), CV_FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(255, 255, 255));
            break;
        }
    }
}

int main( int argc, char** argv ) {

    // using to display
    cv::Mat display = cv::Mat::zeros(800, 800, CV_8UC3);

    cv::namedWindow("Ex_8_6", CV_WINDOW_AUTOSIZE);
    cv::setMouseCallback("Ex_8_6", on_MouseHandle, (void*)&display);

    while(1)
    {
        cv::imshow("Ex_8_6", display);
        char c = static_cast<char>(cv::waitKey(33));
        if(c == 27) break;
    }

    return(0);
}