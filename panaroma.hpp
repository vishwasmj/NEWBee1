#ifndef PANAROMA_H_
#define PANAROMA_H_

#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/stitching.hpp"
#include "Action.hpp"
#pragma once

class Panaroma: public Action {

public:
bool try_use_gpu = false;

int numberofimages =0;
string out_img;
virtual void run();
void printUsage();
};


#endif
