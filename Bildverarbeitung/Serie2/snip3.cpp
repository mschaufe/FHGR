#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


int main() {

    // Teil a)
    // Read image file and copy into image
    // cv::IMREAD_ANYCOLOR If set, the image is read in any possible color format.
    cv::Mat img = cv::imread("moon+is2.png", cv::IMREAD_ANYCOLOR);
    cv::Mat img2 = cv::imread("moon+ISS.png", cv::IMREAD_ANYCOLOR);

    // Teil b)
    if (!img.data || !img2.data)
    {
        std::cout << "Unable to read image" << std::endl;
        return -1;
    }
    std::cout << "Image size of moon+is2 is " << img.size() << std::endl;
    std::cout << "Image size of moon+ISS is " << img.size() << std::endl;

    cv::imshow("moon+is2", img);
    cv::imshow("moon+ISS", img2);

    // Teil c) und Teil d)
    // Prints the number of channels
    std::cout<< "Farbkanäle: " << img.channels() << std::endl;
    cv::Mat imgGray;
    cv::Mat imgGray2;

    // Two if statements that check if the picture is already a Greyscale picture.
    // If not the picture gets convertet into one and saved as a tif format
    if( img.channels() > 2)
    {
        cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
        cv::imshow("Grauwertbild moon+is2", imgGray);
        cv::imwrite("moon+is2.tif", imgGray);
    }
    else std::cout << "Das Bild moon+is2.png ist bereits ein Grauwertbild" << std::endl;

    if( img2.channels() > 2)
    {
        cv::cvtColor(img2, imgGray2, cv::COLOR_BGR2GRAY);
        cv::imshow("Grauwertbild moon+ISS", imgGray2);
        cv::imwrite("moon+ISS.tif", imgGray2);
    }
    else std::cout << "Das Bild moon+ISS.png ist bereits ein Grauwertbild" << std::endl;

    // Teil e)
    double minGray, maxGray;
    cv::Point min_loc, max_loc;
    // Finds the min and max Values to the respective positions.
    cv::minMaxLoc(imgGray, &minGray, &maxGray, &min_loc, &max_loc);
    std::cout << "Minimaler Helligkeitswert: " << minGray << std::endl;
    std::cout << "Maximaler Helligkeitswert: " << maxGray << std::endl;
    std::cout << "Min_loc: " << min_loc << std::endl;
    std::cout << "Max_loc: " << max_loc << std::endl;
    uchar Value_max = 32;
    uchar Value_min = 224;
    double x_max = 297;
    double y_max = 156;

    // Two for loops that change five pixels in the x and y direction to the Value_max at the position max_loc.
    for(size_t i = 0; i < 5; i++)
    {
        imgGray.at<uchar>(y_max, x_max) = Value_max;
        x_max++;
    }
    x_max = 299;
    y_max = 154;
    for(size_t i = 0; i < 5; i++)
    {
        imgGray.at<uchar>(y_max, x_max) = Value_max;
        y_max++;
    }

    double x_min = -2;
    double y_min = 0;
    // Two for loops that change five pixels in the x and y direction to the Value_min at the position min_loc.
    for(size_t i = 0; i < 5; i++)
    {
        imgGray.at<uchar>(y_min, x_min) = Value_min;
        x_min++;
    }
    x_min = 0;
    y_min= -2;
    for(size_t i = 0; i < 5; i++)
    {
        imgGray.at<uchar>(y_min, x_min) = Value_min;
        y_min++;
    }

    cv::imshow("moon+is2.tif", imgGray);
    cv::waitKey(0);

    return 0;
}
