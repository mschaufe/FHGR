#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>


using namespace cv;
using namespace std;

/**
* M A I N   H U   M A T C H I N G
*/
static int I_max = 100;
static int I1_low = 0;
static int I1_high = 2*I_max;
static int iEpsilon = 10;

static vector<vector<Point>> contours;
static vector<vector<Point>> contoursOrg;
static vector<Vec4i> hierarchy;
static Mat gray, grayRef;
static RNG rng(12345);
static vector<Point2f> mc;


static char winMatch[] = "Matched shapes | Press ESC to quit.";
static char winShapes[] = "Shapes | Press ESC to quit.";

static void on_trackbar_shapes(int, void *) {
    /// Draw contours
    Mat dst = Mat::zeros(gray.size(), CV_8UC3);
    vector<Point> approx;
    for (int i = 0; i< contours.size(); i++){
        double epsilon = 0.002*double(iEpsilon)*cv::arcLength(contoursOrg[i], true);
        cv::approxPolyDP(contoursOrg[i], approx, epsilon, true);
        contours[i] = approx;
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(dst, contours, i, color, 1, 8, hierarchy, 0, Point());
    }
    cv::imshow(winShapes, dst);
}

static void on_trackbar_match(int, void *){
    Mat dst2 = Mat::zeros(gray.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); i++) {
        double diff = cv::matchShapes(grayRef, contours[i], CV_CONTOURS_MATCH_I1, 0);
        // std::cout << "diff " << diff << std::endl;
        if ((diff > double(I1_low)/double(I_max)) && (diff < double(I1_high)/double(I_max))) {
            // if (diff > 1.5) {
            Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            drawContours(dst2, contours, i, color, 1, 8, hierarchy, 0, Point());
        }
    }
    imshow(winMatch, dst2);
}

int main(int argc, char *argv[]) {

    // ******************************* load images ************************************ //

    std::cout << std::endl << "Hi! This is " << __FILE__ << "." << std::endl;
    const int colorMode = cv::IMREAD_COLOR;

    cv::String filenameRef = "triangle.png";
    cv::String filenameSearch = "assignment2UB.png";
    if (argc > 1)
        filenameRef = argv[1];
    if (argc > 2)
        filenameSearch = argv[2];

    // reference image (object to find)
    cv::Mat imgRef = cv::imread(filenameRef);
    // image with several objects
    cv::Mat imgSearch = cv::imread(filenameSearch);

    // are images successfully loaded ?
    if ((imgRef.empty()) || (imgSearch.empty())) {
        cout << "Error opening image." << endl;
        return -1;
    }
    cv::imshow("reference", imgRef);
    cv::imshow("measured objects", imgSearch);

    // ******************************* prepare reference image ************************************ //

    // if the pixel value is smaller than the threshold, it is set to 0, otherwise it is set to a maximum value.
    cv::Mat thresh;
    cv::threshold(imgRef, thresh, 127, 255, 0);

    // edge detection with canny on reference image
    cv::cvtColor(imgRef, grayRef, CV_BGR2GRAY);
    cv::Canny(grayRef, grayRef, 100, 200, 3);

    // Find contours on reference image
    vector<vector<Point>> contoursRef;
    vector<Vec4i> hierarchyRef;
    cv::findContours(grayRef, contoursRef, hierarchyRef, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0)); // CV_RETR_TREE

    // ******************************* prepare measured image ************************************ //

    // convert image to gray
    cv::cvtColor(imgSearch, gray, CV_BGR2GRAY);
    //cv::imshow("temp0", gray);

    cv::blur(gray, gray, cv::Size(3, 3));
    //cv::imshow("temp1", gray);

    // edge detection with canny on  image
    cv::Canny(gray, gray, 100, 200, 3);
    cv::imshow("edge0", gray);

    /// Find contours on measured image
    cv::Point p0 = cv::Point(0, 0);
    cv::findContours(gray, contoursOrg, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, p0);
    cv::findContours(gray, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, p0);

    // ************************** "Shapes" approximation output window ******************************** //

    cv::namedWindow(winShapes, WINDOW_NORMAL);
    cv::imshow(winShapes, gray);
    cv::resizeWindow(winShapes, gray.cols, gray.rows);
    cv::createTrackbar("epsilon", winShapes, &iEpsilon, 200, on_trackbar_shapes);
    on_trackbar_shapes(0, NULL);

    cout << "Num objects found: " << contours.size() << std::endl;

    // ******************************* weighted average (Moments) ************************************ //

    // Get the moments
    vector<Moments> mu(contours.size());
    for (int i = 0; i < contours.size(); i++){
        mu[i] = cv::moments(contours[i], false);
    }

    //  Get the area, perimeter, and center-of-mass:
    vector<double>  area(contours.size()); // Area
    vector<double>  len(contours.size());  // Perimeter
    // vector<Point2f> mc(contours.size());  // center-of-mass
    mc = vector<Point2f>(contours.size());   // center-of-mass
    for (int i = 0; i < contours.size(); i++){
        area[i] = mu[i].m00;
        len[i] = cv::arcLength(contours[i], true);// Get contour length for component i
        mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
        cv::circle(imgSearch, mc[i], 3, Scalar(0, 0, 0), 3);
    }
    cv::imshow("measured objects", imgSearch);

    // ************************ "Matched Shapes" output window ****************************** //

    namedWindow(winMatch, WINDOW_NORMAL);
    imshow(winMatch, gray);
    createTrackbar("I1_low", winMatch, &I1_low, 2*I_max, on_trackbar_match);
    createTrackbar("I1_high", winMatch, &I1_high, 2*I_max, on_trackbar_match);
    on_trackbar_match(0, NULL);

    for (;;){
        char c = waitKey(20) & 0xFF;
        if (c == 'q')
            break;
        if (c == 27)
            break;
    }

    cv::destroyAllWindows();
    std::cout << "completed " << __FILE__ << std::endl;
    return 0;
}
