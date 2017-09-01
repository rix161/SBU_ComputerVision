#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int main(int argc, char** argv) {

	Mat img, mod;
	img = imread(argv[1]);

	Mat channel[3];
	if (img.empty()) return 0;

	split(img, channel);
	channel[0] = Mat::zeros(img.rows, img.cols, CV_8UC1);
	channel[1] = Mat::zeros(img.rows, img.cols, CV_8UC1);
	merge(channel, 3, mod);

	imshow("Original", img);
	imshow("Modded", mod);
	waitKey(0);

	return 0;
}