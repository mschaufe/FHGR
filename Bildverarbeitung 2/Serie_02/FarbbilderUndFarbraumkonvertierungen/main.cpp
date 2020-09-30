
/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 18. SEP 2020 *
   * Farbbilder & Farbraumkonvertierungen *
  **************************************/

#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char* argv[]){
    cv::VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);
    cv::Mat frame
    cap >> frame; // Einlesen eines Bildes (Frame) vom VideoCapture Device
    return 0;
}
