
/*************************************
   * Marc Schaufelberger *
   * FHGR *
   * 18. SEP 2020 *
   * Principal Component Analysis *
  **************************************/

#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main( int argc, char** argv ) {
    if( argc != 2){
        std::cout <<" Usage: display_image ImageToLoadAndDisplay" << std::endl;
        return -1;
    }

    // Read the file
    cv::Mat img = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    // Check for invalid input
    if(! img.data ){
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    // Save Pixel>0 in matrix locations
    cv::Mat locations;
    cv::findNonZero(img, locations);

    // transfer to 2x2 matrix
    cv::Mat pcaInput = cv::Mat(locations).reshape(1);

    // Take mean and convert to vector format
    std::vector<float> row_mean;
    cv::reduce(pcaInput, row_mean, 0, CV_REDUCE_AVG,CV_32FC1);
    std::vector<float> centerPoint = std::vector<float>(row_mean);

    // output, image for drawing and display
    cv::Mat dst = img.clone();
    circle(dst, cv::Point(centerPoint[0], centerPoint[1]), 10.0, cv::Scalar(128), 1, 8);

    // Create a window for display.
    namedWindow( "Image Original", cv::WINDOW_AUTOSIZE );
    namedWindow( "Image PCA", cv::WINDOW_AUTOSIZE );

    // Show our image inside it.
    imshow( "Image Original", img );
    imshow( "Image PCA", img );


    // Wait for a keystroke in the window
    cv::waitKey(0);
    return 0;

    return 0;
}
