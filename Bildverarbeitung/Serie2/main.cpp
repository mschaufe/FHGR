/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 09. MAR 2020 *
   * Bilddatei einlesen & abspeichern *
  **************************************/

#include <iostream>
#include <string>
#include <cstring>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

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

void paintCrossmark(cv::Mat *image_gray, cv::Point origin, int size, uchar grayValue) {

    for(int i = -size; i<=size; i++) {
        // check if pixel position is in image
        if (0 <= origin.y+i && origin.y+i < image_gray->rows){
            // change pixel on the y axis
            image_gray->at<uchar>(origin.y+i, origin.x) = grayValue;
        }
        if (0 <= origin.x+i && origin.x+i < image_gray->cols) {
            // change pixel on the x axis
            image_gray->at<uchar>(origin.y, origin.x+i) = grayValue;
        }
    }
}

int main(int argc, char** argv) {

    // create array for image path and gray images
    cv::Mat image_array[10];
    cv::Mat image_gray_array[10];

    // print passed arguments (filepath)
    std::cout << argc << " arguments were passed on:" << std::endl;
    for (size_t i = 0; i < argc; ++i) {
        std::cout << "arg" << i << ": " << argv[i]  << std::endl;
    }
    // new line in terminal
    std::cout << std::endl;

    // print passed filenames
    std::cout << argc-1 << " files were found:" << std::endl;
    for (size_t i = 1; i < argc; ++i) {
        std::cout << getFilenameFromPath(argv[i]) << std::endl;
    }

    // show passed pictures
    for (int i = 1; i < argc; ++i) {
        // load file path in array
        image_array[i] = cv::imread(argv[i], cv::IMREAD_COLOR);
        cv::imshow(getFilenameFromPath(argv[i]), image_array[i]);
    }

    // new line in terminal
    std::cout << std::endl;

    // print gray value
    for (int i = 1; i < argc; ++i) {
        std::cout<< image_array[i].channels() <<  " colour channels in '"  << getFilenameFromPath(argv[i]) <<  "'" << std::endl;
    }
    // new line in terminal
    std::cout << std::endl;

    // convert to gray
    for (int i = 1; i < argc; ++i) {
        cv::cvtColor(image_array[i], image_gray_array[i], cv::COLOR_BGR2GRAY);
    }

    // brightness value
    for (int i = 1; i < argc; ++i) {
        double minGray, maxGray;
        cv::Point min_loc, max_loc;
        cv::minMaxLoc(image_gray_array[i], &minGray, &maxGray, &min_loc, &max_loc);

        // show in Terminal
        std::cout << "minGray: " << minGray << std::endl;
        std::cout << "maxGray: " << maxGray << std::endl;
        std::cout << "min_loc: " << min_loc << std::endl;
        std::cout << "max_loc: " << max_loc << std::endl;
        std::cout << std::endl;

        // define gray color
        uchar lightGray = 180;
        uchar darkGray = 100;

        // mark min and max position
        paintCrossmark(&image_gray_array[i],min_loc,18,lightGray);
        paintCrossmark(&image_gray_array[i],max_loc,18,darkGray);
    }

    // save images
    for (int i = 1; i < argc; ++i) {
        // combine name and ending
        std::string outFileName = getFilenameFromPath(argv[i]) + ".tiff";
        // save file
        cv::imwrite(outFileName, image_gray_array[i]);
    }

    cv::waitKey(0);


    return 0;
}