#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


Mat rotate(Mat src, double angle)   //rotate function returning mat object with parametres imagefile and angle    
{
	Mat dst;      //Mat object for output image file
	Point2f pt(src.cols / 2., src.rows / 2.);          //point from where to rotate    
	Mat r = getRotationMatrix2D(pt, angle, 2.0);      //Mat object for storing after rotation
	warpAffine(src, dst, r, Size(src.cols, src.rows));  ///applie an affine transforation to image.

	/*
	src: Input image
	dst: Output image
	r: Affine transform
	Size(): The desired size of the output image
	*/
	return dst;         //returning Mat object for output image file
}


int main(int argc, char** argv)
{
	// Read the image file
	Mat src = imread("cloud.png");

	// Check for failure
	if (src.empty())
	{
		cout << "Error!!!! image not found.." << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	String windowName = "thank you cloud"; //Name of the window

	namedWindow(windowName); // Create a window




	destroyWindow(windowName); //destroy the created window

	Mat dst;      //Mat object for output image file
	dst = rotate(src, 30);       //rotating image with 30 degree angle

	imshow("src", src);          //displaying input image file
	imshow("dst", dst);         //displaying output image file
	waitKey(0);                     // Wait for any keystroke in the window , to exit press escape
	return 0;
}