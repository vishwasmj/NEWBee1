#pragma once
#include <iostream>
 
using namespace std;
 
// Base class
class Action{

	public:
	virtual void run()=0;
	~Action(){}

};
