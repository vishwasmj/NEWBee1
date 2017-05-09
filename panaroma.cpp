#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/stitching.hpp"
#include "Panaroma.hpp"

using namespace std;
using namespace cv;

void Panaroma::run(){
	vector<Mat> imgs;
	cout<<"It's a Panaroma class inherit the function of abstract class action"<<endl;
	cout<<"Enter the inputs for Panaroma class."<<endl;

        cout << "How many images you want to stich ? "<<endl;
        cin >> numberofimages;

        vector<string> files(numberofimages);
	 //Stitcher::Mode mode = Stitcher::PANORAMA;
	
	cout<<"enter the name of output image :"<<endl;
	cin>>out_img;
	
	for(int i =0; i < numberofimages;i++)
        {
            //read files
            cout << "\nPlease input the image file name (for example: joconde.jpg): "<<endl;
            cin >> files[i];

            Mat img = imread(files[i]);
	if(!img.data ) {
    std::cerr << " Wrong file image";
i--;
continue;
  }
           

            imgs.push_back(img);
        }

	 Mat pano;
	Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
	Stitcher::Status status = stitcher.stitch(imgs, pano);
        //Ptr<Stitcher> stitcher = Stitcher::create(mode, try_use_gpu);
        //Stitcher::Status status = stitcher->stitch(imgs, pano);

        if (status != Stitcher::OK)
        {
            cout << "Can't stitch images, error code = " << int(status) << endl;
            //return 0;
        }
	namedWindow("Image1", WINDOW_NORMAL);
	imshow("Image1", pano);
        imwrite(out_img, pano);
       // imshow(out_img, pano);

        waitKey(0);
        destroyWindow("Image1");
}
