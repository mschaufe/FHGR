/*
* selectROI.cpp
*      Loads image from file and displays it.
*      User can select a ROI using the mouse.
*
*  Created on: Apr. 10, 2018
*      Author: Udo Birk
*
*  Successfully compiled for x64 with VS 2017 and opencv-3.3.1-vc14
*/
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


/// @section List of global variables
// input image
Mat img;

// left mouse button pressed ?
bool lMouseButtonDown = false;

// left mouse button released ?
bool lMouseButtonUp = false;

// image coordinates where the mouse button was pressed
Point ptButtonDownPos;

// image coordinates where the mouse button was released
Point ptButtonUpPos;

// title of the image window
String windowName = "Select rectangle using mouse | Press ESC to quit.";


/// @section mouse callbacks
/// This function gets called after selection of the ROI with the mouse is finished
static void selection_completed() {
    cout << "Selection completed. Coordinates stored in ptButtonDownPos and ptButtonUpPos" << endl;
    // +++++++++++++++++++++++++++++++++++++++++
    // ++    GEBEN SIE HIER IHREN CODE EIN    ++
    // +++++++++++++++++++++++++++++++++++++++++
}


/*! Callback routine:
  mouse_callback wird aufgerufen, wenn vom Betriebssystem ein Mouse-Event
  an das Programm gesendet wird. Das kann z.B. sein: Die Maus wird über einem
  Anwendungsfenster bewegt; eine Maus-Taste wird gerückt oder losgelassen.
  Input:
     event:       Type of mouse event (mouse move, buttonDown, buttonUp...)
     x,y:         Position, at which the mouse event occurred
/*/
static void mouse_callback(int event, int x, int y, int, void *) {
    // start dragging with mouse
    if (event == EVENT_LBUTTONDOWN) // left mouse button pressed
    {
        lMouseButtonDown = true;
        ptButtonDownPos.x = x;
        ptButtonDownPos.y = y;
        cout << "ptButtonDownPos recorded at " << ptButtonDownPos << endl;
    }
    // end dragging with mouse
    if (event == EVENT_LBUTTONUP) // left mouse button released
    {
        // discard selection if too small
        if (abs(x - ptButtonDownPos.x)>20 && abs(y - ptButtonDownPos.y)>20)
        {
            lMouseButtonUp = true;
            ptButtonUpPos.x = x;
            ptButtonUpPos.y = y;
            cout << "ptButtonUpPos recorded at " << ptButtonUpPos << endl;
        }
        else {
            cout << "Please select a bigger region" << endl;
            lMouseButtonDown = false; // abort dragging
        }
    }
    // draw line or rectangle while dragging (mouse button held down)
    if (lMouseButtonDown == true && lMouseButtonUp == false)
    {
        Point pt; // coordinates of the mouse pointer while dragging
        pt.x = x; pt.y = y;

        Mat img2 = img.clone();
        if(img2.channels() == 1) //
            cv::cvtColor(img2, img2, cv::COLOR_GRAY2BGR);

        line(img2, ptButtonDownPos, pt, Scalar(0, 0, 255));
        imshow(windowName, img2);
    }
    // dragging successfully finished
    if (lMouseButtonDown == true && lMouseButtonUp == true)
    {
        selection_completed();
        lMouseButtonDown = false; lMouseButtonUp = false;
    }
}


/// @section Main application entry point
/// main routine (application entry point)
int main(int argc, char* argv[]) {				// accepts command line arguments

    /// @subsection parse command line arguments, if present
    // default image file name:
    cv::String filename = "/Users/marc/Dropbox/05_School/04_FHGR/21_Bildverarbeitung1/Arbeitsblaetter/Serie8/BILD1-08-material/moon+ISS+noise.png"; // change to an existing image file
    if (argc > 1) {
        filename = argv[1];
    }
    img = cv::imread(filename, 0); // Read the file and convert to grayscale
    if (img.empty())          // abort, if no image could be loaded
    {
        std::cout << "ERROR:imread() image not found" << std::endl;
        std::cout << "Press ENTER to quit." << std::endl;
        getchar();
        return(-1);
    }

    /// @subsection Show image on screen:
    namedWindow(windowName);
    imshow(windowName, img);

    /// @subsection Register callback function for mouse events:
    setMouseCallback(windowName, mouse_callback);

    /// @subsection Main application loop:
    char c;  // keyboard input character
    for (;;) {
        c = waitKey(1);
        if (c == 27)    // ESCAPE key pressed
            break;
        if (c == 'q')   // q-key pressed (Quit)
            break;
        // Stop, if window was closed:
        if (cv::getWindowProperty(windowName, cv::WND_PROP_AUTOSIZE) == -1) // quit, if window was closed
            break;
    }
    return 0;
}
