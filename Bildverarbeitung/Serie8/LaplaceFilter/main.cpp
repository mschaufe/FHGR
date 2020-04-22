
/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 22. Apr 2020 *
   * Laplace Filter *
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


int main(int argc, char** argv) {
    // create array for image path
    cv::Mat image_array[10];

    // print passed arguments (filepath)
    std::cout << argc << " arguments were passed on:" << std::endl;
    for (size_t i = 0; i < argc; ++i) {
        std::cout << "arg" << i << ": " << argv[i]  << std::endl;
    }
    // new line in terminal
    std::cout << std::endl;

    // print passed filenames
    std::cout << argc-1 << " file(s) were found:" << std::endl;
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

    cv::waitKey(0);
    return 0;
}
