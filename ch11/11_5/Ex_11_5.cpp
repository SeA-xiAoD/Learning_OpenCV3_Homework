#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cv::Mat original_img = cv::imread("../faces.png");
    cv::Mat persp_trans(original_img.size(), CV_8UC3), persp_trans_and_rot(original_img.size(), CV_8UC3);
    cv::Mat one_step(original_img.size(), CV_8UC3);
    cv::imshow("Ex_11_5_original", original_img);

    // Perspective transform
    cv::Point2f srcQuad1[] = {
            cv::Point2f(0, 0), // top-left
            cv::Point2f(original_img.cols - 1, 0), // top-right
            cv::Point2f(0, original_img.rows - 1), // bottom-left
            cv::Point2f(original_img.cols - 1, original_img.rows - 1), // bottom-right
    };

    cv::Point2f dstQuad1[] = {
            cv::Point2f(0, 0), // top-left
            cv::Point2f((original_img.cols - 1)*0.9, (original_img.rows - 1)*0.2), // top-right
            cv::Point2f(0, original_img.rows - 1), // bottom-left
            cv::Point2f((original_img.cols - 1)*0.9, (original_img.rows - 1)*0.8), // bottom-right
    };

    cv::Mat warp_mat1 = cv::getPerspectiveTransform(srcQuad1, dstQuad1);
    cv::warpPerspective(original_img, persp_trans, warp_mat1, persp_trans.size());
    cv::imshow("Ex_11_5_perspective_transform", persp_trans);

    // Rotation
    cv::rotate(persp_trans, persp_trans_and_rot, cv::ROTATE_180);
    cv::imshow("Ex_11_5_perspective_transform_and_rotation", persp_trans_and_rot);

    // One step
    cv::Point2f srcQuad2[] = {
            cv::Point2f(0, 0), // top-left
            cv::Point2f(original_img.cols - 1, 0), // top-right
            cv::Point2f(0, original_img.rows - 1), // bottom-left
            cv::Point2f(original_img.cols - 1, original_img.rows - 1), // bottom-right
    };

    cv::Point2f dstQuad2[] = {
            cv::Point2f(original_img.cols - 1, original_img.rows - 1), // top-left
            cv::Point2f((original_img.cols - 1)*0.1, (original_img.rows - 1)*0.8), // top-right
            cv::Point2f(original_img.cols - 1, 0), // bottom-left
            cv::Point2f((original_img.cols - 1)*0.1, (original_img.rows - 1)*0.2), // bottom-right
    };

    cv::Mat warp_mat2 = cv::getPerspectiveTransform(srcQuad2, dstQuad2);
    cv::warpPerspective(original_img, one_step, warp_mat2, persp_trans.size());
    cv::imshow("Ex_11_5_one_step", one_step);

    cv::waitKey(0);

    return 0;
}
