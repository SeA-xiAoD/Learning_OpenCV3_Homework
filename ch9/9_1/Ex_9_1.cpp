#include <opencv2/opencv.hpp>
#include <iostream>

cv::Rect rect1, rect2, rect3, rect4;

void mouse_callback(int event, int x, int y, int flags, void* param)
{
    switch (event){
        case cv::EVENT_LBUTTONDOWN:
        {
            if(rect1.contains(cv::Point(x, y)))
            {
                std::cout << "Image1(" << x << "," << y << ")" << std::endl;
            }
            else if(rect2.contains(cv::Point(x, y)))
            {
                std::cout << "Image2(" << x - rect2.x << "," << y << ")" << std::endl;
            }
            else if(rect3.contains(cv::Point(x, y)))
            {
                std::cout << "Image3(" << x << "," << y - rect3.y << ")" << std::endl;
            }
            else if(rect4.contains(cv::Point(x, y)))
            {
                std::cout << "Image4(" << x - rect4.x << "," << y - rect4.y << ")" << std::endl;
            }
            else
            {
                std::cout << "THis click is not on these 4 images." << std::endl;
            }
            break;
        }
    }
}

void help()
{
    std::cout << "Input 4 images." << std::endl;
    std::cout << "For example: ./Ex_9_1 image1.jpg image2.jpg image3.jpg image4.jpg" << std::endl;
}

int main(int argc, char **argv)
{
    if(argc != 5)
    {
        help();
        return 1;
    }

    cv::Mat img1 = cv::imread(argv[1]);
    cv::Mat img2 = cv::imread(argv[2]);
    cv::Mat img3 = cv::imread(argv[3]);
    cv::Mat img4 = cv::imread(argv[4]);

    int display_width = (img1.size().width + img2.size().width) > (img3.size().width + img4.size().width) ?
                        (img1.size().width + img2.size().width) : (img3.size().width + img4.size().width);
    int display_height = (img1.size().height + img3.size().height) > (img2.size().height + img4.size().height) ?
                        (img1.size().height + img3.size().height) : (img2.size().height + img4.size().height);

    cv::Mat display = cv::Mat::zeros(display_height, display_width, CV_8UC3);

    img1.copyTo(display.rowRange(0, img1.size().height).colRange(0, img1.size().width));
    rect1 = cv::Rect(0, 0, img1.size().width, img1.size().height);

    img2.copyTo(display.rowRange(0, img2.size().height).colRange(display_width - img2.size().width, display_width));
    rect2 = cv::Rect(display_width - img2.size().width, 0, img2.size().width, img2.size().height);

    img3.copyTo(display.rowRange(display_height - img3.size().height, display_height).colRange(0, img3.size().height));
    rect3 = cv::Rect(0, display_height - img3.size().height, img3.size().width, img3.size().height);

    img4.copyTo(display.rowRange(display_height - img4.size().height, display_height).colRange(display_width - img4.size().width, display_width));
    rect4 = cv::Rect(display_height - img4.size().width, display_height - img4.size().height, img4.size().width, img4.size().height);

    cv::namedWindow("Ex_9_1", cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("Ex_9_1", mouse_callback);

    while(1)
    {
        cv::imshow("Ex_9_1", display);
        char c = cv::waitKey(33);
        if(c == 27) break;
    }

    return 0;
}