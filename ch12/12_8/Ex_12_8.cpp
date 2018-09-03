#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread("../faces.png", cv::IMREAD_GRAYSCALE);
    cv::Mat gaussian_blur, i_f_gaussian_blur;

    clock_t start, end;

    // Gaussian blur
    start = clock();
    cv::GaussianBlur(img, gaussian_blur, cv::Size(51, 51), 1);
    end = clock();
    cout << "Gaussian blur: " << static_cast<double>(end - start)/CLOCKS_PER_SEC << endl;

    // DFT Gaussian blur

    cv::waitKey(0);

    return 0;
}
