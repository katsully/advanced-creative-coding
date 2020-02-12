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

	void draw();
	void Shape::setRotationValue(int r);

	ofColor color;
	int startingX;
	int startingY;
	int width;
	int height;

private:
	int rotationValue;

	
};

