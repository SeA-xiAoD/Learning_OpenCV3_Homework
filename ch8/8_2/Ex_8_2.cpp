#include <opencv2/opencv.hpp>

using namespace std;

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
    cv::Mat& img = *(cv::Mat*) param;
    switch (event)
    {
        case CV_EVENT_LBUTTONDOWN:
        {
            int b = static_cast<int>(img.at<cv::Vec3b>(x, y)[0]);
            int g = static_cast<int>(img.at<cv::Vec3b>(x, y)[1]);
            int r = static_cast<int>(img.at<cv::Vec3b>(x, y)[2]);
            cout << b << " " << g << " " << r << endl;
            cv::putText(img, "(" + to_string(b) + "," + to_string(g) + "," + to_string(r) + ")", cv::Point(x, y),
            CV_FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(b,g,r), 2);
            break;
        }
    }
}

int main(int argc, char** argv) {

    cv::Mat img = cv::imread("../faces.png");
    cv::namedWindow("Ex_8_2", CV_WINDOW_AUTOSIZE);

    cv::setMouseCallback("Ex_8_2", on_MouseHandle, (void*)&img);

    while(1)
    {
        cv::imshow("Ex_8_2", img);
        char c = static_cast<char>(cv::waitKey(33));
        if(c == 27) break;
    }

    return 0;
}
