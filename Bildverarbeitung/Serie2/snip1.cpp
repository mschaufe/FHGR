#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


int main(int argc, char** argv) {

    // create array for image path
    cv::Mat image_array[10];

    char winName[20];

    // pass path to parameter
    std::cout << argc << " arguments were passed on:" << std::endl;
    for (size_t i = 0; i < argc; ++i) {
        std::cout << "arg" << i << ": " << argv[i] << std::endl;
        if(i>0){
            // load file path in array
            image_array[i-1] = cv::imread(argv[i], cv::IMREAD_COLOR);

            sprintf(winName,"Window%d",i);

            // show original images
            cv::imshow(winName, image_array[i-1]);
        }
    }
    std::cout << std::endl;


    cv::waitKey(0);


    // load file path in to variable
    cv::Mat imgGray;

    std::cout << "Number of channels: " << img1.channels() << std::endl;
    std::cout << std::endl;

    cv::cvtColor(img1, imgGray, cv::COLOR_BGR2GRAY);


    double minGray, maxGray;
    cv::Point min_loc, max_loc;
    cv::minMaxLoc(imgGray, &minGray, &maxGray, &min_loc, &max_loc);

    std::cout << "minGray: " << minGray << std::endl;
    std::cout << "maxGray: " << maxGray << std::endl;
    std::cout << "min_loc: " << min_loc << std::endl;
    std::cout << "max_loc: " << max_loc << std::endl;
    std::cout << std::endl;

    cv::putText(img1, "+", cv::Point(min_loc), cv::FONT_HERSHEY_PLAIN, 3,  cv::Scalar(0,255,0),8);
    cv::putText(img1, "+", cv::Point(max_loc), cv::FONT_HERSHEY_PLAIN, 3,  cv::Scalar::all(255),2);

    cv::imwrite("WindowTitle.tiff", imgGray);




    return 0;
}
