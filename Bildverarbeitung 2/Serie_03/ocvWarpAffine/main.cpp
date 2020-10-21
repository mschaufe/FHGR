/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 21. OKT 2020 *
   * Affine Transformation *
  **************************************/

#include<iostream>
#include <string>
#include <cstring>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>


// create array for images
cv::Mat img,crop,imgOut;


// left and right mouse button pressed ?
bool lMouseButtonDown = false;
bool lMouseButtonUp = false;

// image coordinates where the mouse button was pressed and released
cv::Point ptButtonDownPos;
cv::Point ptButtonUpPos;

// title of the image window
cv::String windowName = "Select by dragging your mouse | Press ESC to quit.";

std::string getFilenameFromPath(std::string  filename){
    // Remove directory if present.
    // Do this before extension removal incase directory has a period character.
    const size_t last_slash_idx = filename.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        filename.erase(0, last_slash_idx + 1);
    }

    // Remove extension if present.
    const size_t period_idx = filename.rfind('.');
    if (std::string::npos != period_idx)
    {
        filename.erase(period_idx);
    }
    return filename;
}


static void selection_completed_roi() {
    // selection roi cordinate
    cv::Rect box,boxOut;
    box.width = cv::abs(ptButtonDownPos.x - ptButtonUpPos.x);
    box.height = cv::abs(ptButtonDownPos.y - ptButtonUpPos.y);
    box.x = cv::min(ptButtonDownPos.x, ptButtonUpPos.x);
    box.y = cv::min(ptButtonDownPos.y, ptButtonUpPos.y);

    // make new img from selection
    crop = cv::Mat(img, box);

    // Kopieren des Bildinhaltes
    imgOut = img.clone();

    // Kopieren des Rechtecks
    boxOut = cv::Rect(box);

    // Erstellen einer affinen Form
    cv::Mat affineForm(2, 3, CV_32FC1);

    // Transformationsdefinition
    //affineForm = (cv::Mat_<float>(2, 3) << 1.0, 0.0, 0, 0.25, 1.0, 0); // Variante 1

    double angle = 25;
    int x = 30;
    int y = 10;
    double zoom = 0.5; // affine transformation settings
    cv::Point center = cv::Point(x, y);
    affineForm = getRotationMatrix2D(center, angle, zoom); // Variante 2

    cv::Mat warp_dst = cv::Mat::zeros(boxOut.height, boxOut.width, img.type()); 
    warpAffine(crop, warp_dst, affineForm, warp_dst.size()); 
    warp_dst.copyTo(imgOut(boxOut));

    // out first Transorm
    cv::namedWindow("Affine Transformation");
    cv::imshow("Affine Transformation", imgOut);


}
static void mouse_callback_roi(int event, int x, int y, int, void *) {
    x = cv::max(cv::min(x, img.cols), 0); // crop, if button was released outside the figure
    y = cv::max(cv::min(y, img.rows), 0); // crop, if button was released outside the figure
    // start dragging with mouse
    if (event == cv::EVENT_LBUTTONDOWN){ // left mouse button pressed
        lMouseButtonDown = true;
        ptButtonDownPos.x = x;
        ptButtonDownPos.y = y;
        std::cout << "ptButtonDownPos: recorded at " << ptButtonDownPos << std::endl;
    }
    // end dragging with mouse
    if (event == cv::EVENT_LBUTTONUP){ // left mouse button released
        // discard selection if too small
        if (abs(x - ptButtonDownPos.x)>20 && abs(y - ptButtonDownPos.y)>20){
            lMouseButtonUp = true;
            ptButtonUpPos.x = x;
            ptButtonUpPos.y = y;
            std::cout << "ptButtonUpPos:   recorded at " << ptButtonUpPos << std::endl;
        }else {
            std::cout << "Please select a bigger region" << std::endl;
            lMouseButtonDown = false; // abort dragging
        }
    }
    // draw line or rectangle while dragging (mouse button held down)
    if (lMouseButtonDown == true && lMouseButtonUp == false){
        cv::Point pt; // coordinates of the mouse pointer while dragging
        pt.x = x; pt.y = y;

        cv::Mat img2 = img.clone();
        if (img2.channels() == 1) //
            cv::cvtColor(img2, img2, cv::COLOR_GRAY2BGR);

        cv::rectangle(img2, ptButtonDownPos, pt, cv::Scalar(0, 0, 255));
        cv::imshow(windowName, img2);
    }
    // dragging successfully finished
    if (lMouseButtonDown == true && lMouseButtonUp == true){
        lMouseButtonDown = false; lMouseButtonUp = false;
        selection_completed_roi();
    }
}

int main(int argc, char** argv) {

    // default image file name:
    cv::String filename = "dali.png";
    if (argc > 1) {
        filename = argv[1];
    }

    // Read the file and convert to grayscale
    img = cv::imread(filename, 0);

    // abort, if no image could be loaded
    if (img.empty())
    {
        std::cout << "ERROR:imread() image not found" << std::endl;
        std::cout << "Press ENTER to quit." << std::endl;
        getchar();
        return(-1);
    }

    // console output name and size
    std::cout << "name: "  << getFilenameFromPath(filename) << std::endl;
    std::cout << "size: " << img.cols << " x " << img.rows << std::endl;
    std::cout <<  std::endl;

    // @subsection Register callback function for mouse events:
    cv::namedWindow(windowName);
    cv::imshow(windowName, img);

    /// @subsection Register callback function for mouse events:
    cv::setMouseCallback(windowName, mouse_callback_roi);



    // @subsection Main application loop:
    char c;  // keyboard input character
    for (;;) {
        c = cv::waitKey(0);
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
