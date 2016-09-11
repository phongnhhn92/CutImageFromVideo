#include "opencv2/highgui/highgui.hpp"
#include <thread>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{
	VideoCapture cap("sample_cut.mp4"); // open the video file for reading
	int imageCount = 0; //image count

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}


	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	cout << "Frame per seconds : " << fps << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frame, currentImage;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}
		
		//Save Image
		int currentFrame = cap.get(CV_CAP_PROP_POS_FRAMES);
		cout << currentFrame << endl;
		if (currentFrame % 30 == 0)
		{
			cap >> currentImage;
			imwrite(to_string(imageCount) + ".jpg", currentImage);
			cout << "Saved Image" << endl;
			imageCount++;
		}
		


		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}