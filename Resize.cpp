#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Resize.hpp"

using namespace std;
using namespace cv;

void Resize::run(){
cout<<"It's a resize class inherit the function of abstract class action"<<endl;
cout<<"Enter the inputs for resize class."<<endl;
string img,out_img;
int width, height;
cout<<"enter the name of input image :"<<endl;
cin>>img;
cout<<"enter the name of output image :"<<endl;
cin>>out_img;
cout<<"enter the height :"<<endl;
cin>>height;
cout<<"enter the width :"<<endl;
cin>>width;
Mat original_img = imread(img);

  if(!original_img.data ) {
    std::cerr << " Wrong file image";
  }
Mat cropped_img;
namedWindow("WINDOW1", WINDOW_NORMAL);
namedWindow("WINDOW2", WINDOW_AUTOSIZE);
  imshow("WINDOW1", original_img);
  resize(original_img, cropped_img, Size(width, height));
  imshow("WINDOW2", cropped_img);
  imwrite(out_img, cropped_img);
waitKey (0);
  std::cout << "Resized done";
destroyWindow("WINDOW1");
destroyWindow("WINDOW2");

}

