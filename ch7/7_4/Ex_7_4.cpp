#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat A(3, 2, CV_32FC1);
    float temp[6] = {1, 1, 0, 1, -1, 1};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
            A.at<float>(i, j) = temp[i * 2 + j];
    }

    // a
    cv::Mat At_A = A.t() * A;
    cout << "At*A:\n" << At_A << endl;
    cv::Mat eigenvalues, eigenvectors;
    cv::eigen(At_A, eigenvalues, eigenvectors);
    cout << "eigenvalues:\n" << eigenvalues << "\neigenvectors:\n" << eigenvectors << endl;
    cout << "singular values:\n" << sqrt(eigenvalues.at<float>(0, 0)) <<
         " " << sqrt(eigenvalues.at<float>(1, 0)) << endl;

    // b
    cv::Mat W, U, Vt;
    cv::SVD::compute(A, W, U, Vt);
    cout << "\nVt:\n" << Vt.t() << "\nU:\n" << U << endl;

    // c
    cv::Mat sigma = cv::Mat::zeros(2, 2, CV_32FC1);
    sigma.at<float>(0, 0) = W.at<float>(0, 0);
    sigma.at<float>(1, 1) = W.at<float>(1, 0);
    cout << "\nsigma:\n" << sigma << endl;
    cout << "verify A = U *sigma * Vt:\n"<<  U * sigma * Vt << endl;

    // d
    cv::SVD svd(A);
    svd.compute(A, W, U, Vt);
    cout << "\nUsing the cv::SVD object:" << endl;
    cout << "Vt:\n" << Vt.t() << "\nU:\n" << U << endl;

    return 0;
}
