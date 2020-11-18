#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>


int main() {

    cv::Mat star = cv::imread("star4.png", cv::IMREAD_COLOR);
    cv::Mat cell = cv::imread("cell.tif", cv::IMREAD_COLOR);
    cv::Mat coin = cv::imread("coin.png", cv::IMREAD_COLOR);

    // Check if it is possible to open the images
    if(star.empty() || cell.empty() || coin.empty())
    {
        std::cout << "Could not read the image" << std::endl;
        return 1;
    }

    // a)
    cv::Mat dst1, dst2, dst3, dst4, dst5, dst6;
    cv::Mat SE = cv::Mat::ones(3, 3, CV_8U); // 3x3 binary filter kernel
    // You can try more different parameters
    cv::morphologyEx(star, dst1, cv::MORPH_DILATE, SE);  // Hellster Wert der Maske wird an den Objekträndern Pixel hinzugefügt.
    cv::morphologyEx(star, dst2, cv::MORPH_ERODE, SE);   // Kleinster Wert der Maske wird an den Randpixel (von weisen Objekten) entfernt.
    cv::morphologyEx(star, dst3, cv::MORPH_OPEN, SE);    // (Erosion + Dilation)
    cv::morphologyEx(star, dst4, cv::MORPH_CLOSE, SE);   // (Dilation + Erosion)

    cv::imshow("Original Bild", star);
    cv::imshow("Dilate",dst1);
    cv::moveWindow("Dilate", 342, 0);
    cv::imshow("Erode",dst2);
    cv::moveWindow("Erode", 684, 0);
    cv::imshow("Open",dst3);
    cv::moveWindow("Open", 342, 313);
    cv::imshow("Close",dst4);
    cv::moveWindow("Close", 684, 313);

    // b)
    // Eigen definiertes Struktur-Element
    cv::Size SEsize = cv::Size(5, 5); // Kernel size = Grösse des binären Filters
    cv::Mat SE2 = cv::getStructuringElement(cv::MORPH_ELLIPSE, SEsize); // CROSS, ELLIPSE, RECT
    cv::morphologyEx(star, dst5, cv::MORPH_DILATE, SE2);

    cv::imshow("Structuring Element",dst5);
    cv::moveWindow("Structuring Element", 1026, 0);

    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::waitKey(0);

    // c)
    cv::Mat edges;
    cv::Canny(cell, edges, 50, 200);
    cv::imshow("Canny", edges);
    cv::Mat M = cv::Mat::ones(3, 3, CV_8U); // 3x3 binary filter kernel
    cv::morphologyEx(edges, dst6, cv::MORPH_DILATE, M);

    cv::imshow("Edges",dst6);
    cv::moveWindow("Edges", 191, 0);

    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::waitKey(0);

    // d)
    cv::Mat coin_gray;
    cv::Mat coin_thresh;
    cv::Mat img_floodfill_inv;
    // Convert into a Grayscale image and set a threshold
    cvtColor( coin, coin_gray, cv::COLOR_BGR2GRAY);
    threshold(coin_gray,coin_thresh,220,255,cv::THRESH_BINARY_INV);
    // Floodfill from point (0, 0)
    cv::Mat img_floodfill = coin_thresh.clone();
    cv::floodFill(img_floodfill, cv::Point(0, 0), cv::Scalar(255));
    // Invert floodfilled image
    cv::bitwise_not(img_floodfill, img_floodfill);
    // Obtain foreground by OR-combining both images
    cv::Mat img_out = (coin_thresh | img_floodfill);

    cv::imshow("filled", img_out);

    // e)
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::RNG rng(12345); // paint with alternating colors
    cv::findContours(img_out, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
    cv::Mat drawing = cv::Mat::zeros(img_out.size(), CV_8UC3);
    for(size_t i = 0; i< contours.size(); i++)
    {
        cv::Scalar color = cv::Scalar(rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255));
        drawContours(drawing, contours, (int)i, color, 1, 8, hierarchy, 0, cv::Point());
    }

    cv::imshow( "Contours", drawing );
    cv::moveWindow("Contours", 308, 0);
    cv::waitKey(0);

    return 0;
}