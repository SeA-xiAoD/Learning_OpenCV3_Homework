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

    cv::Mat img = cv::imread( argv[1] );
    img = img.colRange(0, 300).rowRange(0, 300);

    // a
    cv::LineIterator it1(img, cv::Point(10, 10), cv::Point(10, 100), 4);
    cv::LineIterator it2(img, cv::Point(10, 10), cv::Point(10, 100), 8);
    int count_1 = 0, count_2 = 0;
    for(int i = 0; i < it1.count; i++)
        count_1++;
    for(int i = 0; i < it2.count; i++)
        count_2++;
    std::cout << "a: " << "Line1: " << count_1 << " Line2: " << count_2 << std::endl;

    // b
    it1 = cv::LineIterator(img, cv::Point(10, 10), cv::Point(100, 100), 4);
    it2 = cv::LineIterator(img, cv::Point(10, 10), cv::Point(100, 100), 8);
    count_1 = 0, count_2 = 0;
    for(int i = 0; i < it1.count; i++)
        count_1++;
    for(int i = 0; i < it2.count; i++)
        count_2++;
    std::cout << "b: " << "Line1: " << count_1 << " Line2: " << count_2 << std::endl;

    // c
    it1 = cv::LineIterator(img, cv::Point(10, 10), cv::Point(100, 100), 4);
    it2 = cv::LineIterator(img, cv::Point(10, 10), cv::Point(100, 100), 8);
    count_1 = 0, count_2 = 0;
    for(int i = 0; i < it1.count; i++)
        count_1++;
    for(int i = 0; i < it2.count; i++)
        count_2++;
    std::cout << "c: " << "true length = " << std::to_string(sqrt(90*90 + 90*90)) << " Line1: " << count_1 << " Line2: " << count_2 << std::endl;

    return 0;
}
