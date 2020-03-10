/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 09. MAR 2020 *
   * Punktoperationen *
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

cv::Mat imgToHistogram(cv::Mat1b const& image)
{
    // Set histogram bins count
    int bins = 512;
    int histSize[] = {512,400};

    // Set ranges for histogram bins
    float lranges[] = {0, 256};
    const float* ranges[] = {lranges};

    // create matrix for histogram
    cv::Mat hist;
    int channels[] = {0};

    // create matrix for histogram visualization
    int const hist_height = 400;
    cv::Mat3b hist_image = cv::Mat3b::zeros(hist_height, bins);

    cv::calcHist(&image, 1, channels, cv::Mat(), hist, 1, histSize, ranges, true, false);

    double max_val=0;
    minMaxLoc(hist, 0, &max_val);

    // visualize each bin
    for(int b = 0; b < bins; b++) {
        float const binVal = hist.at<float>(b);
        int   const height = cvRound(binVal*hist_height/max_val);
        cv::line
                ( hist_image
                        , cv::Point(b, hist_height-height), cv::Point(b, hist_height)
                        , cv::Scalar::all(255)
                );
    }
    return hist_image;
}

int main(int argc, char** argv) {

    // create array for image path and gray images
    cv::Mat image_array[10];
    cv::Mat image_gray_array[10];

    // print passed arguments (filepath)
    std::cout << argc << " arguments were passed on:" << std::endl;
    for (size_t i = 0; i < argc; ++i) {
        std::cout << "arg" << i << ": " << argv[i] << std::endl;
    }

    // new line in terminal
    std::cout << std::endl;

    // print passed filenames
    std::cout << argc - 1 << " files were found:" << std::endl;
    for (size_t i = 1; i < argc; ++i) {
        std::cout << getFilenameFromPath(argv[i]) << std::endl;
    }

    for (int i = 1; i < argc; ++i) {
        // load file path in array
        image_array[i] = cv::imread(argv[i], cv::IMREAD_COLOR);

        // clipping
        image_array[i] = cv::min(image_array[i], 255);

        // convert to gray and invert
        cv::cvtColor(image_array[i], image_gray_array[i], cv::COLOR_BGR2GRAY);

        // show passed pictures
        cv::imshow(getFilenameFromPath(argv[i]), image_gray_array[i]);

        // show histogram
        cv::imshow("histogram: "+getFilenameFromPath(argv[i]), imgToHistogram(image_gray_array[i]));

        // save histogram
        std::string outFileName = "histogram_"+getFilenameFromPath(argv[i]) + ".tiff"; // combine name and ending
        cv::imwrite(outFileName, imgToHistogram(image_gray_array[i])); // save file

    }
    cv::waitKey(0);
}