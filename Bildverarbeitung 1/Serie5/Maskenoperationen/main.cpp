/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 23. MAR 2020 *
   * Maskenoperationen *
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

    // create array for image path and gray images
    cv::Mat image_array[10];
    cv::Mat dst,
            dst1,
            dst2,
            dst_s1,
            dst_s2,
            dst_s1_com,
            dst_s2_com;

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

    int ddepth = -1; /// Datentyp Ergebnis-Bild = Datentyp Eingangs-Bild
    cv::Point anchor = cv::Point(-1, -1); /// relative Position des Filters zum berechneten Pixel.
    double delta = 0; /// Grauwert-Offset (addiert zum Ergebnis-Bild)
    int borderType = cv::BORDER_CONSTANT; /// Wie soll am Rand verfahren werden


    // kernel for the low pass filter.
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << 1./9, 1./9, 1./9, 1./9, 1./9, 1./9, 1./9, 1./9, 1./9);
    cv::Mat kernel1 = cv::Mat::zeros(cv::Size(11,11), CV_32FC1); // with initialization
    kernel1 = kernel1 * 0 + 1. / (11*11);

    // kernel for the high pass filter.
    cv::Mat kernel2 = (cv::Mat_<float>(3, 3) << 0, 1, 0, 1,-4, 1, 0, 1, 0);

    // sobel template
    cv::Mat sobel1 = (cv::Mat_<float>(3, 3) << -1./3, -2./3, -1./3, 0,0, 0, 1./3, 2./3, 1./3);
    cv::Mat sobel2 = (cv::Mat_<float>(3, 3) << -1./3, 0, 1./3, -2./3,0, 2./3, -1./3, 0, 1./3);

    for (int i = 1; i < argc; ++i) {
        // load file path in array
        image_array[i] = cv::imread(argv[i], cv::COLOR_BGR2GRAY);
        cv::imshow("Original_"+getFilenameFromPath(argv[i]), image_array[i]);

        // low pass
        cv::filter2D(image_array[i], dst, ddepth, kernel, anchor, delta, cv::BORDER_DEFAULT);
        cv::imshow("LowPass_3x3_"+getFilenameFromPath(argv[i]), dst);

        cv::filter2D(image_array[i], dst1, ddepth, kernel1, anchor, delta, cv::BORDER_DEFAULT);
        cv::imshow("LowPass_11x11_"+getFilenameFromPath(argv[i]), dst1);

        // high pass
        cv::filter2D(image_array[i], dst2, ddepth, kernel2, anchor, delta, cv::BORDER_DEFAULT);
        cv::imshow("HighPass_3x3_"+getFilenameFromPath(argv[i]), dst2);

        // sobel 1
        cv::filter2D(image_array[i], dst_s1, ddepth, sobel1, anchor, delta, cv::BORDER_DEFAULT);
        cv::imshow("Sobel1_3x3_"+getFilenameFromPath(argv[i]), dst_s1);

        // sobel 2
        cv::filter2D(dst_s1, dst_s2, ddepth, sobel2, anchor, delta, cv::BORDER_DEFAULT);
        cv::imshow("Sobel2_3x3_"+getFilenameFromPath(argv[i]), dst_s2);

        // sobel combined
        cv::filter2D(image_array[i], dst_s1_com, CV_32FC3, sobel1, anchor, delta, cv::BORDER_DEFAULT);
        cv::filter2D(image_array[i], dst_s2_com, CV_32FC3, sobel2, anchor, delta, cv::BORDER_DEFAULT);
        cv::pow(dst_s1_com / 255.0, 2.0, dst_s1_com); // dst_sobel1_com = dst_sobel1_com^2
        cv::pow(dst_s2_com / 255.0, 2.0, dst_s2_com); // dst_sobel2_com = dst_sobel2_com^2
        cv::sqrt(dst_s1_com + dst_s2_com, dst_s2_com); // dst_sobel2_com = sqrt(dst_sobel2_com+dst_sobel1_com)

        cv::filter2D(dst_s1, dst_s2, ddepth, sobel2, anchor, delta, cv::BORDER_DEFAULT);
        cv::imshow("Sobel_comb_3x3_"+getFilenameFromPath(argv[i]), dst_s1_com);
    }

    cv::waitKey(0);


    return 0;
}