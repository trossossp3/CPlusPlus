#include "pch.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main(int argc, const char* argv[])
{
	/*String imageName("../data/kirby.jpg"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}*/
	 Mat src = imread("../data/contours.png", IMREAD_COLOR); // Load an image
	 Mat src_gray;
	if (src.empty())
	{
		return -1;
	}
	cvtColor(src, src_gray, COLOR_BGR2GRAY); // Convert the image to Gray
	Mat dst;
	Mat img;
	threshold(src_gray, dst, 0, 255, THRESH_OTSU);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); Point(-1, -1);
	
	morphologyEx(dst, img, MORPH_OPEN, kernel, Point(-1, -1), 1);

	String window_name = "test";
	
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	findContours(img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	Mat img_rgb;
	cvtColor(img, img_rgb, COLOR_GRAY2BGR);
	
	
	for (size_t i = 0; i < contours.size(); i++)
	{
		float contourArea = contourArea(contours[i]);
		if (contourArea > 1000 || contourArea < 300)
		{
			continue;
		}
		//drawContours(img, contours, i, Scalar(255, 0, 255), 3, 8, hierarchy, 0, Point());
		Scalar color(255, 0, 255);
		drawContours(img_rgb, contours, i, color, 2, 8, hierarchy);
		//drawContours(img, contours, i, Scalar(255, 0, 255), 3, 8, hierarchy, 0, Point());
	}

	namedWindow(window_name, WINDOW_AUTOSIZE); // Create a window to display results

	imshow(window_name, img_rgb);
	waitKey(0);
	
}