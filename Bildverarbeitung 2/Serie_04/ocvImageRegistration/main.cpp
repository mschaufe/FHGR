#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

// create array for images
cv::Mat img1,img2,img_trans, img_out;

// title of the image window
cv::String windowName = "Bildueberlagerung";

int main() {
    // Read the file and convert to grayscale
    img1 = cv::imread("westconcordaerial.png");
    img2 = cv::imread("westconcordorthophoto.png");

    // abort, if no image could be loaded
    if (img1.empty() && img2.empty()){
        std::cout << "ERROR:imread() image not found" << std::endl;
        std::cout << "Press ENTER to quit." << std::endl;
        getchar();
        return(-1);
    }

    // select Points
    std::vector<cv::Point2f> p1,p2;

    p1.emplace_back(123, 305);
    p1.emplace_back(316, 81);
    p1.emplace_back(130, 91);

    p2.emplace_back(135, 299);
    p2.emplace_back(348, 131);
    p2.emplace_back(177, 109);

    // mark points in image
    for (int i = 0; i < 3; ++i) {
        cv::drawMarker(img1,p1[i],0);
        cv::drawMarker(img2,p2[i],0);
    }

    // affine transformation
    cv::Mat hAff = getAffineTransform(p1, p2);
    warpAffine(img1, img_trans, hAff, img2.size());

    // overlay img2 and transformed img1
    double alpha = 0.5; double beta;
    beta = ( 1.0 - alpha );
    addWeighted( img_trans, alpha, img2, beta, 0.0, img_out);

    // show images
    cv::imshow("img1", img1);
    cv::imshow("img2", img2);
    cv::imshow(windowName, img_out);


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
