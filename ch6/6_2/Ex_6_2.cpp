#include <opencv2/opencv.hpp>

void help(char** argv ) {
    std::cout << "\n"
              << "A simple OpenCV program that loads and displays an image from disk\n"
              << argv[0] <<" <path/filename>\n"
              << "For example:\n"
              << argv[0] << " ../fruits.jpg\n"
              << std::endl;
}


int main( int argc, char** argv ) {

    if (argc != 2) {
        help(argv);
        return 0;
    }

    // a
    cv::Mat img = cv::imread( argv[1] );
    cv::Mat one_channel_img;
    cv::cvtColor(img, one_channel_img, CV_BGR2GRAY);
    cv::cvtColor(one_channel_img, img, CV_GRAY2BGR);

    // b
    cv::putText(img, "Exercise 6_2", cv::Point(100, 100), cv::FONT_HERSHEY_PLAIN, 1.5, cv::Scalar(255, 255, 255), 2);

    cv::namedWindow( "Ex_6_2", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Ex_6_2", img );
    cv::waitKey( 0 );
    cv::destroyWindow( "Ex_6_2" );

    return 0;
}
