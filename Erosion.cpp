#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Erosion.hpp"

//Define namespaces
using namespace std;
using namespace cv;

//Function defination
void Erosion::run(){
	string img;
	
	
	cout<<"It's a erosion class inherit the function of abstract class action"<<endl;
	cout<<"Enter the inputs for erosion class."<<endl;

	cout<<"enter the name of input image :"<<endl;
	cin>>img;
	cout<<"enter the erosion size :"<<endl;
	cin>>erosion_size;
	cout<<"enter the erosion type like 'MORPH_RECT,MORPH_CROSS,MORPH_ELLIPSE':"<<endl;
	cin>>erosion_type;

	//Reading the file and cheking it
	Mat original_img = imread(img);

	if(!original_img.data ) {
	    std::cerr << " Wrong file image";
	   }

	// Create window
	namedWindow("Erosion", WINDOW_NORMAL);
	// show original image
	imshow("Erosion", original_img);
	
	Mat element = getStructuringElement( erosion_type,
                                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                       Point( 0, 0 ) );
	// Apply the erosion operation
	Mat erosion_dst;
	erode( original_img, erosion_dst, element );

	// show erode image
	imshow( "Erosion1", erosion_dst );

	waitKey (0);

	// Destroy the windows
	destroyWindow("Erosion");
	destroyWindow("Erosion1");
	cout << "Erosion done"<<endl;
	
  }

   

