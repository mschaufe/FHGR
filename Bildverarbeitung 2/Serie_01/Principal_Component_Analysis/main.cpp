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

    // TEIL B

    // transfer to 2x2 matrix
    cv::Mat pcaInput = cv::Mat(locations).reshape(1);

    // Convert to floating point numbers !! important for reduce
    pcaInput.convertTo(pcaInput, CV_32F);

    // Take mean and convert to vector format
    cv::Mat row_mean;

    // Average value of the two columns
    reduce(pcaInput, row_mean, 0, CV_REDUCE_AVG);
    std::vector<float> centerPoint = std::vector<float>(row_mean);
    std::cout << "Center: " << row_mean << std::endl;

    // output, image for drawing and display
    cv::Mat dst = img.clone();
    circle(dst, cv::Point(centerPoint[0], centerPoint[1]), 10.0, cv::Scalar(128), 1, 8);


    // TEIL C
    int num_components = 2;
    // Principal Component Analyse
    cv::PCA pca(pcaInput, cv::Mat(), CV_PCA_DATA_AS_ROW, num_components);


    // TEIL D



    std::vector<float> ePC1 = pca.eigenvectors.row(0);
    // Vector times scale equals lengt of line
    float scale = 60;
    ePC1[0] = ePC1[0]*scale;
    ePC1[1] = ePC1[1]*scale;

    cv::Point p1 = cv::Point(centerPoint[0]-(ePC1[0]), centerPoint[1]-(ePC1[1]));
    cv::Point p2 = cv::Point(centerPoint[0]+(ePC1[0]), centerPoint[1]+(ePC1[1]));
    cv::line(dst, p1, p2, cv::Scalar(128), 2);
    std::cout << "Vector : " << ePC1[0] << ", " << ePC1[1] <<std::endl;

    // Create a window for display.
    namedWindow( "Image Original", cv::WINDOW_AUTOSIZE );
    namedWindow( "Image PCA", cv::WINDOW_AUTOSIZE );

    // Show our image inside it.
    imshow( "Image Original", img );
    imshow( "Image PCA", dst );


    // Wait for a keystroke in the window
    cv::waitKey(0);
    return 0;

    return 0;
}
