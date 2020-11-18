#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

using namespace cv;


#ifdef CV_CALIB_CB_ADAPTIVE_THRESH  // openCV version 3.x
int findChessboardFastFlag = CV_CALIB_CB_FAST_CHECK;
int findChessboardFlags = CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE | findChessboardFastFlag;
#else                               // openCV version 4.x
int findChessboardFastFlag = CALIB_CB_FAST_CHECK;
int findChessboardFlags = CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE | findChessboardFastFlag;
#endif

void mmm(cv::String output) {
	std::cout << output << std::endl;
}

int main(int argc, char* argv[]) {				// accepts command line arguments

	// default image file name:
	cv::String filename = "Schachbrett.png";    // change to an existing image file
	if (argc > 1) {
		filename = argv[1];
	}

	cv::Mat img = cv::imread(filename, 1);
	if (!img.data)
	{
		std::cout << "ERROR: could not read input image" << std::endl;
		return(0);
	}

    /*
	mmm("resizing image ...");
	//--------------------------
	cv::Mat imgGray, imgResized;
	bool bResizeImage = true;
	if (bResizeImage) {
		// Find corners is slow on large images, so we reduce
		// the image size to a quarter of its original size
		int faktor = 4;
		cv::resize(img, imgResized, cv::Size(img.cols / faktor, img.rows / faktor), 0, 0, cv::INTER_LANCZOS4);
		cv::cvtColor(imgResized, imgGray, cv::COLOR_BGR2GRAY);
	} else {
		imgResized = img.clone();
		cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	}
	cv::imshow("imgGray", imgGray);
	//cv::moveWindow("imgGray", 20, 20);
    */

    cv::Mat imgGray, imgResized;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

	// Definition der Kalibrationsmuster (Anzahl innerer Ecken)
	cv::Size dimh = cv::Size(4, 51); // Anzahl innerer Ecken (d.h. Seitenlänge minus 1)
	cv::Size dimv = cv::Size(33, 4);

	cv::Rect box;
	std::vector<std::vector<cv::Vec2f>> veccornerPoints(4);
	std::vector<cv::Vec2f> cornerPoints;

	// devide image into 4 regions of interest (boxes) in order
	// to mask out areas we are presently not interested in
	mmm("detecting top (first) calibration pattern ...");
	//------------------------------------------------------
	box.width = imgGray.cols; box.height = imgGray.rows / 2;  box.x = 0; box.y = imgGray.rows / 2;
	// Create a clone image in which the other calibration regions are set to zero
	cv::Mat first = imgGray.clone();
	first(box) = cv::Scalar(0); // clear outside area
	bool found = cv::findChessboardCorners(first, dimh, veccornerPoints[0], findChessboardFlags);

	//cv::imshow("first", first);
	//cv::waitKey(20);

	mmm("detecting bottom (second) calibration pattern ...");
	//------------------------------------------------------
	box.width = imgGray.cols; box.height = imgGray.rows / 2;  box.x = 0; box.y = 0;
	cv::Mat second = imgGray.clone();
	second(box) = cv::Scalar(0);
	cv::findChessboardCorners(second, dimh, veccornerPoints[1], findChessboardFlags);

	mmm("detecting right (third) calibration pattern ...");
	//------------------------------------------------------
	box.width = imgGray.cols / 2; box.height = imgGray.rows / 2;  box.x = imgGray.cols / 2; box.y = 0;
	cv::Mat third = imgGray.clone();
	third(box) = cv::Scalar(0);
	cv::findChessboardCorners(third, dimv, veccornerPoints[2], findChessboardFlags);

	mmm("detecting left (fourth) calibration pattern ...");
	//------------------------------------------------------
	box.width = imgGray.cols / 2; box.height = imgGray.rows;  box.x = 0; box.y = 0;
	cv::Mat fourth = imgGray.clone();
	fourth(box) = cv::Scalar(0);
	cv::findChessboardCorners(fourth, dimv, veccornerPoints[3], findChessboardFlags);

	mmm("drawing calibration patterns ...");
	//------------------------------------------------------
	cv::Mat dst = img.clone();
	drawChessboardCorners(dst, dimh, veccornerPoints[0], found); // Anzeige der gefundenen Cornerpunkte
	drawChessboardCorners(dst, dimh, veccornerPoints[1], found);
	drawChessboardCorners(dst, dimv, veccornerPoints[2], found);
	drawChessboardCorners(dst, dimv, veccornerPoints[3], found);

	cv::imshow("Chessboard", dst);
	cv::waitKey(0);

	//Highlight first, fourth, and last chessboardcorner of all four patterns
	std:int radius = 10;
	int last = 0;
	cv::Scalar red = cv::Scalar(0, 0, 255);
	cv::Scalar green = cv::Scalar(0, 255, 0);
	cv::Scalar blue = cv::Scalar(255, 0, 0);

    // Aufgabe b, Weltkoordinaten bestimmen ------------------------------
    Mat dst2 = img.clone();
    float squareEdgeLength = abs(veccornerPoints[0][1][1] - veccornerPoints[0][0][1]); // Seitenlänge ausfinden
    std::vector<Point2f> pointWorld;
    int xOffset = veccornerPoints[0][0][0]; // startpunkt x richtung
    int yOffset = veccornerPoints[0][0][1]; // startpunkt y richtung
    for (int i = 0; i < dimh.height; i++) // durch alle eckpunkte einmal durchgehen
    {
        for (int j = 0; j < dimh.width; j++)
        {
            Point2f pt = Point2f(xOffset - i * squareEdgeLength, yOffset + j * squareEdgeLength); // punkte wo sie sein sollten
            pointWorld.push_back(pt);
            cv::drawMarker(dst2, pt, red, MARKER_CROSS, 10, 1); // TILTED_CROSS, 10, 1); // kreuz zeichnen
        }
    }

    cv::imshow("Weltcoord", dst2);
    cv::waitKey(0);

// Transformationsmatrix finden und anwenden -------------------------
    Mat transImg;
    Mat transform = findHomography(veccornerPoints[0], pointWorld); // Transformationsmatrix finden
    //Mat transform = getAffineTransform(veccornerPoints[0], pointWorld);
    warpPerspective(img, transImg, transform, img.size()); // Transformation auf Bild anwenden
    cv::imshow("warped", transImg);

	cv::waitKey(0);

	mmm("fertig");
	return 0;
}