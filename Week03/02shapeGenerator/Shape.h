#pragma once
#include "C:\Users\kmsul\Documents\oF\libs\openFrameworks\app\ofBaseApp.h"

#include "ofMain.h"

class Shape :
	public ofBaseApp
{
public:
	Shape();
	Shape(int x, int y);
	~Shape();
	void update();
	void draw();

	ofColor color;
	int xPos;
	int yPos;
	int scale;
	bool increase;
	// string shape;
};

