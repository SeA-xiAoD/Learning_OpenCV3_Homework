#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::RNG rng = cv::theRNG();
    // a
    cout << "Random floating-point: " << endl << (float)rng << endl << (float)rng << endl << (float)rng << endl << endl;

    // b
    cout << "Random floating-point: " << endl << rng.gaussian(1.0) << endl << rng.gaussian(1.0) << endl << rng.gaussian(1.0) << endl << endl;

    // c
    cout << "Random floating-point: " << endl << static_cast<int>((uchar)rng) << endl << static_cast<int>((uchar)rng) << endl << static_cast<int>((uchar)rng) << endl << endl;

    return 0;
}
