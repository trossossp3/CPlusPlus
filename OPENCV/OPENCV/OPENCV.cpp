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
	
	for (size_t i = 0; i < contours.size(); i++)
	{
		drawContours(img, contours, i, Scalar(255, 0, 255), 3, 8, hierarchy, 0, Point());
	}

	namedWindow(window_name, WINDOW_AUTOSIZE); // Create a window to display results

	imshow(window_name, dst);
	waitKey(0);
	
}