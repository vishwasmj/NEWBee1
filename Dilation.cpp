#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Dilation.hpp"

//Define namespaces
using namespace std;
using namespace cv;

//Function defination
void Dilation::run(){
	string img;
	
	
	cout<<"It's a dilation class inherit the function of abstract class action"<<endl;
	cout<<"Enter the inputs for dilation class."<<endl;

	cout<<"enter the name of input image :"<<endl;
	cin>>img;
	cout<<"enter the dilation size :"<<endl;
	cin>>dilation_size;
	cout<<"enter the dilation type like 'MORPH_RECT,MORPH_CROSS,MORPH_ELLIPSE':"<<endl;
	cin>>dilation_type;

	//Reading the file and cheking it
	Mat original_img = imread(img);

	if(!original_img.data ) {
	    std::cerr << " Wrong file image";
	   }

	// Create window
	namedWindow("Dilation", WINDOW_NORMAL);
	// show original image
	imshow("Dilation", original_img);

	Mat element = getStructuringElement( dilation_type,
                                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                       Point( 0, 0 ) );
	// Apply the dilation operation
	Mat dilation_dst;
	dilate( original_img, dilation_dst, element );
	
	// show dilate image
	imshow( "Dilation1", dilation_dst );

	waitKey (0);
	// Destroy the windows
	destroyWindow("Dilation");
	destroyWindow("Dilation1");
	cout << "Dilation done"<<endl;
	
  }

   

