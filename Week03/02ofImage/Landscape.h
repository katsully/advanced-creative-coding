#pragma once
#include "C:\Users\kmsul\Documents\oF\libs\openFrameworks\app\ofBaseApp.h"
#include "ofMain.h"
class Landscape :
	public ofBaseApp
{
public:
	Landscape();
	Landscape(int x, int y);
	~Landscape();
	void Landscape::draw();

	ofImage pic;
	int startingX;
	int startingY;
	int rotationValue;

};

