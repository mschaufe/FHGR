#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace cv;

#ifdef CV_CALIB_CB_ADAPTIVE_THRESH  // openCV version 3.x
int findChessboardFlags = CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE | CV_CALIB_CB_FAST_CHECK;
int findChessboardFastFlag = CV_CALIB_CB_FAST_CHECK;
#else                               // openCV version 4.x
int findChessboardFlags = CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE | CALIB_CB_FAST_CHECK;
int findChessboardFastFlag = CALIB_CB_FAST_CHECK;
#endif

// const name for output window caption
const String window_capture_name = "Live Video | Press ESC to quit.";

// Size dim : Anzahl innerer Ecken (d.h. Seitenlänge minus 1), (width, height)
// const Size dim = Size(6, 7);  // Size(6,7) = Ausdruck
// const Size dim = Size(5, 8);  // Size(6,9) = smartphone
//const Size dim = Size(6, 9); // smartphone
const Size dim = Size(8, 5);

bool  IS_SEARCH_ON = true;
bool  FLIP_FRAME = true;

double knownDistance = 30; // in cm
double knownSize = sqrt(pow((double)dim.width-1.0, 2.0) + pow((double)dim.height-1.0, 2.0));
double focalLength = (100 * knownDistance) / knownSize;
int checkerboardLen = dim.width*dim.height;

int main(/*int argc, char* argv[]*/)
{
    //VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);
    VideoCapture cap(0);
    // Check if camera opened successfully
    if (!cap.isOpened()) {
        cout << "Error opening video stream" << endl;
        return -1;
    }

    Mat frame, gray, dst;
    // Check if we can read from the camera
    cap >> frame;
    if (frame.empty())
    {
        cout << "Error reading image from camera" << endl;
        return -1;
    }
    cout << "Image size=(" << frame.cols << "," << frame.rows << ")" << endl;

    cout << "=====================================================" << endl;
    cout << "Instructions:" << endl;
    cout << "-------------" << endl;
    cout << "Hold the checkerboard pattern (" << dim.width << "," << dim.height << ") in front of " << endl;
    cout << "the camera, at a fixed distance d=" << knownDistance << "cm." << endl;
    cout << "Then press 'c' to calibrate the camera." << endl;
    cout << "=====================================================" << endl;

    namedWindow(window_capture_name);

    int cornerCount;
    bool found = false;
    Point2f euclDist;

    while (true) {
        cap >> frame;
        if (frame.empty())
        {
            break;
        }
        if(FLIP_FRAME)
            cv::flip(frame, frame, 1);
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        cornerCount = 0;
        vector<Vec2f> cornerPoints;
        if (IS_SEARCH_ON) {
            cv::resize(gray, dst, cv::Size(), 0.5, 0.5);
            found = cv::findChessboardCorners(dst, dim, cornerPoints, findChessboardFlags);
        }
        else {
            found = false;
        }
        frame.copyTo(dst);

        /*
        // If window is closed, exit application
        if (cv::getWindowProperty(window_capture_name, cv::WND_PROP_AUTOSIZE) == -1)
            break;
        */

        // Show the frames
        if (found) {
            cornerCount = (int)(cornerPoints.size());
            // refine search on large image matrix (gray) using non-fast search
            if(cv::findChessboardCorners(gray, dim, cornerPoints, findChessboardFlags- findChessboardFastFlag)) { //   findCornerSubPix(gray, &cornerPoints, cornerCount, cvSize(5, 5), cvSize(-1, -1), cvTermCriteria(CV_TERMCRIT_ITER, 100, 0.1));
                // , CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE
                // criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
                drawChessboardCorners(dst, dim, cornerPoints, found);
                euclDist = (cornerPoints[cornerCount - 1] - cornerPoints[0]);
                double len = sqrt(pow(euclDist.x, 2.0) + pow(euclDist.y, 2.0));
                double dist = (focalLength*knownSize) / len;

                // lighten the upper part of the image (40 rows)
                Rect region_of_interest = Rect(0, 0, frame.cols, 40);
                Mat image_roi = dst(region_of_interest);
                image_roi = image_roi / 2 + 127;

                // write distance string to image
                cv::String str = cv::format("distance (cm): %4.2f", dist);
                cv::putText(dst, str, Point(10, 25), FONT_HERSHEY_SIMPLEX, 0.7, 255, 2);
            }
            else {
                found = false;
                cout << "Refined search failed." << endl;
            }
        }

        char key = (char)(waitKey(30) & 0xff);
        if (key == 'q' || key == 27) { break; }
        if (key == 'c') {
            if (found) {
                euclDist = (cornerPoints[cornerCount - 1] - cornerPoints[0]);
                double len = sqrt(pow(euclDist.x, 2.0) + pow(euclDist.y, 2.0));
                focalLength = (len * knownDistance) / knownSize;
                cout << "focal length: " << focalLength << endl;
            }
            else {
                cout << "--- chessboard not detected ---" << endl;
            }

        }
        imshow(window_capture_name, dst);
        if (key == 's') { IS_SEARCH_ON = !IS_SEARCH_ON; } // switch off search for checkerboard pattern
        if (key == 'f') { FLIP_FRAME = !FLIP_FRAME; } // toggle left/right flipping of camera image

    }

    return 0;
}