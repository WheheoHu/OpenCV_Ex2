#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
int main() {

	Mat img = imread("Lenna_(test_image).png");

	Mat img_cvt;
	cvtColor(img, img_cvt, COLOR_RGB2GRAY);
	Mat img_OTSU;
	threshold(img_cvt, img_OTSU, 0, 255, THRESH_BINARY + THRESH_OTSU);


	auto kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat img_Erode;
	erode(img_cvt, img_Erode, kernel);

	Mat img_dilate;
	dilate(img_cvt, img_dilate, kernel);

	Mat img_morphOPEN;
	morphologyEx(img_cvt, img_morphOPEN, MORPH_OPEN, kernel);

	Mat img_morphCLOSE;
	morphologyEx(img_cvt, img_morphCLOSE, MORPH_CLOSE, kernel);
	cv::imshow("RGB", img);
	cv::imshow("RGB2GARY", img_cvt);
	cv::imshow("OTSU", img_OTSU);

	cv::imshow("Erode", img_Erode);
	cv::imshow("Dilate", img_dilate);

	cv::imshow("morphOPEN", img_morphOPEN);
	cv::imshow("morphCLOSE", img_morphCLOSE);
	waitKey(0);
}