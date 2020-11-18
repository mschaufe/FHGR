#include <stdio.h>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include<iostream>
// https://docs.opencv.org/3.1.0/d1/d5c/tutorial_py_kmeans_opencv.html

using namespace std;
using namespace cv;

char window_name[] = "K-means clustering | Press ESC to quit.";

cv::Mat img, dst;
cv::Mat clusteredImage;
cv::Mat Samples;
int clusterCount = 3;

bool convertToHSV = false;

// function prototype
void on_trackbar(int clusterCount, void*);

int main(int argc, char* argv[])
{
    //a.) Bild einlesen, anzeigen
    cv::String filename;
    // filename = "D:/birkudo/Pictures/publicDomain/birds_cruz_1870573_1920.jpg";
    // filename = "D:/birkudo/Pictures/publicDomain/birds_tower_small.png";
    // filename = "D:/birkudo/Pictures/publicDomain/queensBuilding2small.png";
    // filename = "D:/birkudo/Pictures/Camera Roll/LegoColorUSp_sm.png";
    filename = "lego_parts.jpg";
    img = cv::imread(filename, cv::IMREAD_ANYCOLOR);
    namedWindow("original", CV_WINDOW_KEEPRATIO);
    cv::imshow("original", img);

    if (convertToHSV)
        cvtColor(img, img, COLOR_BGR2HSV);

    //In Nx3 Matrix umwandeln (3 Spalten für RGB)
    Samples = cv::Mat(img.rows * img.cols, 3, CV_32F);
    for (int y = 0; y < img.rows; y++)
        for (int x = 0; x < img.cols; x++)
            for (int z = 0; z < 3; z++)
                Samples.at<float>(y + x * img.rows, z) = img.at<Vec3b>(y, x)[z];

    clusteredImage = cv::Mat(img.size(), img.type());
    cv::namedWindow(window_name);
    createTrackbar("clusterCount", window_name, &clusterCount, 16, on_trackbar);
    on_trackbar(clusterCount, NULL);

    Samples.convertTo(Samples, CV_32F);

    for (;;) {
        if (cv::getWindowProperty(window_name, cv::WND_PROP_AUTOSIZE) == -1)
            break;
        imshow(window_name, dst);
        char c = waitKey(20) & 0xFF;
        if (c == 'q')
            break;
        if (c == 27)
            break;
        if (c == 'h') {
            convertToHSV = true;
            on_trackbar(clusterCount, NULL);
        }
        if (c == 'r') {
            convertToHSV = false;
            on_trackbar(clusterCount, NULL);
        }
    }

    cv::destroyAllWindows();
    clusteredImage.release();
}

void on_trackbar(int clusterCount, void*)
{
    Mat labels;
    Mat centers;

    int attempts = 5;
    int maxIterations = 10;
    double eps = 1.0;
    // cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS, maxIterations, eps);
    cv::TermCriteria criteria = cv::TermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, maxIterations, eps);

    kmeans(Samples, max(clusterCount, 1), labels, criteria, attempts, KMEANS_PP_CENTERS, centers);

    for (int y = 0; y < img.rows; y++)
        for (int x = 0; x < img.cols; x++)
        {
            int cluster_idx = labels.at<int>(y + x * img.rows, 0);	// label-Wert
            clusteredImage.at<Vec3b>(y, x)[0] = centers.at<float>(cluster_idx, 0);
            clusteredImage.at<Vec3b>(y, x)[1] = centers.at<float>(cluster_idx, 1);
            clusteredImage.at<Vec3b>(y, x)[2] = centers.at<float>(cluster_idx, 2);
        }

    cv::resize(clusteredImage, dst, cv::Size(), 2, 2);

    if (convertToHSV)
        cvtColor(dst, dst, COLOR_HSV2BGR);
}
