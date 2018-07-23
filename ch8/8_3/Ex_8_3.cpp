#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;

bool mouse_press = false;
cv::Point left_up, right_down;

// rected_img: using in button up. temp_img: using in button down.
cv::Mat rected_img, temp_img;

// selected_rect: using to record the selected rect after button up.
cv::Rect selected_rect(0, 0, 0, 0);

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
    cv::Mat& img = *(cv::Mat*) param;
    img.copyTo(temp_img);
    switch (event)
    {
        case CV_EVENT_LBUTTONDOWN:
        {
            mouse_press = true;
            left_up = cv::Point(x, y);
            img.copyTo(rected_img);
            break;
        }
        case CV_EVENT_MOUSEMOVE:
        {
            if(mouse_press)
            {
                right_down = cv::Point(x, y);
                cv::rectangle(temp_img, left_up, right_down, cv::Scalar(0,0,255));
            }
            break;
        }
        case CV_EVENT_LBUTTONUP:
        {
            mouse_press = false;
            right_down = cv::Point(x, y);
            cv::rectangle(rected_img, left_up, right_down, cv::Scalar(0,0,255));
            selected_rect = cv::Rect(left_up, right_down);
            break;
        }
    }
}

void draw_histogram(const cv::Mat& img)
{
    std::vector<cv::Mat> bgr_plane;
    cv::split(img, bgr_plane);
    int histSize = 8;
    float range[] = {0, 256};
    const float * histRange = {range};

    // calculate BGR histogram for each channel
    cv::Mat b_hist, g_hist, r_hist;
    cv::calcHist(&bgr_plane[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange);
    cv::calcHist(&bgr_plane[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange);
    cv::calcHist(&bgr_plane[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange);

    // get max count
    double b_hist_max, g_hist_max, r_hist_max;
    cv::minMaxLoc(b_hist, NULL, &b_hist_max, NULL, NULL);
    cv::minMaxLoc(b_hist, NULL, &g_hist_max, NULL, NULL);
    cv::minMaxLoc(b_hist, NULL, &r_hist_max, NULL, NULL);
    double max_count = r_hist_max > (b_hist_max > r_hist_max ? b_hist_max : r_hist_max) ? r_hist_max : (b_hist_max > r_hist_max ? b_hist_max : r_hist_max);

    // draw histogram
    cv::Mat hist(480, 500, CV_8UC3);
    cv::namedWindow("Histogram", CV_WINDOW_AUTOSIZE);
    for(int i = 0; i < histSize; i++)
    {
        cv::rectangle(hist, cv::Point(i*20, 500), cv::Point(i*20+20, cvRound(500*b_hist.at<float>(i,0)/max_count)), cv::Scalar(255,0,0));
        cv::rectangle(hist, cv::Point(160+i*20, 500), cv::Point(160+i*20+20, cvRound(500*g_hist.at<float>(i,0)/max_count)), cv::Scalar(0,255,0));
        cv::rectangle(hist, cv::Point(320+i*20, 500), cv::Point(320+i*20+20, cvRound(500*r_hist.at<float>(i,0)/max_count)), cv::Scalar(0,0,255));
    }
    cv::imshow("Histogram", hist);
}

int main(int argc, char** argv) {

    cv::Mat img = cv::imread("../faces.png");
    cv::namedWindow("Ex_8_3", CV_WINDOW_AUTOSIZE);

    cv::setMouseCallback("Ex_8_3", on_MouseHandle, (void*)&img);
    img.copyTo(rected_img);

    while(1)
    {
        if(mouse_press)
            cv::imshow("Ex_8_3", temp_img);
        else
        {
            cv::imshow("Ex_8_3", rected_img);
            if(selected_rect.width != 0 && selected_rect.height != 0)
                draw_histogram(img.rowRange(selected_rect.y, selected_rect.y + selected_rect.height).colRange(selected_rect.x, selected_rect.x + selected_rect.width));
        }
        char c = static_cast<char>(cv::waitKey(33));
        if(c == 27) break;
    }

    return 0;
}
