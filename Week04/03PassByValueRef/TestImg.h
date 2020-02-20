#pragma once

// #include "C:\Users\kmsul\Documents\oF\libs\openFrameworks\app\ofBaseApp.h"
#include "ofMain.h"

class TestImg
{
public:
	TestImg();
	~TestImg();

	float x;
	float y;

	// here the parameter is a copy of the image
	// void draw(ofImage img);
	
	// with the * the function now takes a pointer to the original image
	void draw(ofImage* img);
};

