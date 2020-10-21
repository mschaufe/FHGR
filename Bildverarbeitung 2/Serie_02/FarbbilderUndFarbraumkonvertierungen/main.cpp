
/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 18. SEP 2020 *
   * Farbbilder & Farbraumkonvertierungen *
  **************************************/

#include <iostream>
#include <cstdlib>

#include "opencv2/videoio.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


const cv::String window_capture_name = "Video Capture";
const cv::String window_detection_name = "Object Detection";

cv::Scalar hsv_lower_green = cv::Scalar(50, 55, 55);
cv::Scalar hsv_upper_green = cv::Scalar(70, 255, 255);

cv::Scalar hsv_lower_blue = cv::Scalar(110, 50, 50);
cv::Scalar hsv_upper_blue = cv::Scalar(130, 255, 255);

int hue_low,hue_high;
int max_value_H = 100;


cv::Scalar ScalarBGR2HSV(uchar B, uchar G, uchar R) {
    cv::Mat hsv;
    cv::Mat rgb(1,1, CV_8UC3, cv::Scalar(R,G,B));
    cv::cvtColor(rgb,hsv, CV_BGR2HSV);
    return cv::Scalar(hsv.data[0], hsv.data[1]*100/255, hsv.data[2]*100/255);
}

static void on_hue_low_trackbar(int, void *) {

    hue_low = cv::min(hue_high - 1, hue_low); // unterer Wert muss kleiner als der obere sein setTrackbarPos("Hue low", window_mask_name, hue_low);

}

int main(int argc, char* argv[]){
    cv::VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);

    std::cout << ScalarBGR2HSV(0,255,0) << std::endl;

    cv::createTrackbar("Hue low", "Hue low", &hue_low, max_value_H, on_hue_low_trackbar);

    cv::Mat frame,frame_HSV,frame_mask;
    while (true) {
        cap >> frame;
        if(frame.empty()){
            break;
        }

        cv::cvtColor(frame,frame_HSV, cv::COLOR_BGR2HSV);
        cv::inRange(frame_HSV, hsv_lower_green, hsv_upper_green, frame_mask);

        // Show the frames
        imshow(window_capture_name, frame);
        imshow(window_detection_name, frame_mask);
        char key = (char) cv::waitKey(30);
        if (key == 'q' || key == 27){
            break;
        }
    }
    return 0;
}
