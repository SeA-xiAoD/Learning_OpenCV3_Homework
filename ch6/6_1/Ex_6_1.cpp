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

    cv::Mat img = cv::imread( argv[1], -1 );

    if( img.empty() ) return -1;

    // circle
    cv::circle(img, cv::Point(100, 100), 50, cv::Scalar(255, 255, 255), 2);

    // ellipse 1
    cv::ellipse(img, cv::Point(200, 200), cv::Size(100, 50), 0, 180+45, 180+135, cv::Scalar(0, 0, 255), 2);

    // ellipse 2
    cv::ellipse(img, cv::RotatedRect(cv::Point(300, 100), cv::Size2f(100, 50), 30), cv::Scalar(0, 255, 0), 2);

    // line
    cv::line(img, cv::Point(200, 300), cv::Point(200, 400), cv::Scalar(0, 255, 255), 2);

    // rectangle
    cv::rectangle(img, cv::Point(400, 400), cv::Point(500, 600), cv::Scalar(255, 255, 0), 2);

    // polyLine
    cv::Point points[1][5];
    points[0][0] = cv::Point(500, 10);
    points[0][1] = cv::Point(500, 100);
    points[0][2] = cv::Point(600, 100);
    points[0][3] = cv::Point(600, 50);
    points[0][4] = cv::Point(700, 10);
    const cv::Point* ppt[1] = {points[0]};
    int npt[] = {5};
    cv::polylines(img, ppt, npt, 1, 1, cv::Scalar(255, 0, 255), 2);

    cv::namedWindow( "Ex_6_1", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Ex_6_1", img );
    cv::waitKey( 0 );
    cv::destroyWindow( "Ex_6_1" );

    return 0;
}
