#ifndef DILATION_H_
#define DILATION_H_

#include "Action.hpp"
#pragma once

using namespace cv;
//Erosion class inherit the function and variable of Action
class Dilation: public Action {

public:
	//Variable and function declaration
	int dilation_type;
	int dilation_elem = 0;
	int dilation_size = 0;
	int const max_elem = 2;
	int const max_kernel_size = 21;	

	virtual void run();
};


#endif
