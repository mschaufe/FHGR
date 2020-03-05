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
        std::cout << "arg" << i << ": " << argv[i] << std::endl;
    }
    std::cout << std::endl;

    // print passed filenames
    std::cout << argc-1 << " files were found:" << std::endl;
    for (size_t i = 1; i < argc; ++i) {
        std::cout << getFilenameFromPath(argv[i]) << std::endl;
    }
    std::cout << std::endl;

    char winName[20];
    
    // show passed pictures
    for (size_t i = 0; i < argc-1; ++i) {
        // load file path in array
        image_array[i] = cv::imread(argv[i], cv::IMREAD_COLOR);

        // get filename form path in a string
        std::string mywinName = getFilenameFromPath(argv[i]);

        // convert string to char[]
        char cWinName[mywinName.size() + 1];
        strcpy(cWinName, mywinName.c_str());	// or pass &s[0]

        std::cout << cWinName << '\n';

        //printf("Pic: %s",cWinName);
        sprintf(winName,"Pic: %s",cWinName);
        // show original images
        cv::imshow(winName, image_array[i]);
    }


    std::cout << std::endl;

    cv::waitKey(0);


    return 0;
}