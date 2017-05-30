#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Darken.hpp"

using namespace std;
using namespace cv;

void Darken::run(){
	string img;
	double alpha; /**< Simple contrast control */
	int beta;  /**< Simple brightness control */
	cout<<"It's a darken class inherit the function of abstract class action"<<endl;
	cout<<"Enter the inputs for Darken class."<<endl;

	cout<<"enter the name of input image :"<<endl;
	cin>>img;

	Mat original_img = imread(img);

	if(!original_img.data ) {
		std::cerr << " Wrong file image";
	   }
	Mat new_image = Mat::zeros( original_img.size(), original_img.type() );

 	// Initialize values
 	cout<<" Basic Darken Transforms "<<std::endl;	
	cout<<"-------------------------"<<std::endl;
	cout<<"* Enter the alpha value [-3.0 to 1.0 ]: ";std::cin>>alpha;
	cout<<"* Enter the beta value [0-100]: "; std::cin>>beta;

	// Do the operation new_image(i,j) = alpha*image(i,j) + beta
 	for( int y = 0; y < original_img.rows; y++ )
    	{ for( int x = 0; x < original_img.cols; x++ )
         { for( int c = 0; c < 3; c++ )
              {
      		new_image.at<Vec3b>(y,x)[c] =
         	saturate_cast<uchar>( alpha*( original_img.at<Vec3b>(y,x)[c] ) + beta );
             }
    	}
    }

	namedWindow("Darken", WINDOW_NORMAL);
	namedWindow("New Image", 1);
	imshow("Darken", original_img);
	imshow("New Image", new_image);

	// Wait until user press some key
 	waitKey(0);
	cout << "Darken done";
	destroyWindow("Darken");
	destroyWindow("New Image");

 }

