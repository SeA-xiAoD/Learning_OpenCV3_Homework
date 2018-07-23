#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int position_slider_position = 0;
int pause_slider_position = 1;
int g_run = 1;
cv::VideoCapture g_cap;

// distance : distance frames between each increment
int dis = 0;

void onPositionTrackbarSlide( int pos, void *)
{
    g_cap.set( CV_CAP_PROP_POS_FRAMES, pos * dis);
}

void onPauseTrackbarSlide(int pos, void*)
{
    g_run = pos;
}

int main( int argc, char** argv ) {

    cv::namedWindow( "Ex_8_4", cv::WINDOW_AUTOSIZE );

    g_cap.open("../Megamind.avi");

    int frames = (int) g_cap.get( CV_CAP_PROP_FRAME_COUNT  );
    int tmpw   = (int) g_cap.get( CV_CAP_PROP_FRAME_WIDTH  );
    int tmph   = (int) g_cap.get( CV_CAP_PROP_FRAME_HEIGHT );
    double fps = g_cap.get(CV_CAP_PROP_FPS);

    dis = frames / 10;

    cv::createTrackbar("Position", "Ex_8_4", &position_slider_position, 10, onPositionTrackbarSlide);
    cv::createTrackbar("Pause", "Ex_8_4", &pause_slider_position, 1, onPauseTrackbarSlide);

    cv::Mat frame;
    while(1)
    {
        if(g_run)
        {
            g_cap >> frame;
            if(frame.empty()) break;

            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);

            if(current_pos % dis == 0)
            {
                current_pos = current_pos / dis;
                cv::setTrackbarPos("Position", "Ex_8_4", current_pos);
            }
        }
        cv::imshow("Ex_8_4", frame);

        char c = static_cast<char>(cv::waitKey(1000 / fps));
        if(c == 27) break;
    }

    return(0);
}