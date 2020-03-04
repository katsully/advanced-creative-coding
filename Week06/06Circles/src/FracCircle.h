#pragma once

#include "ofMain.h"

class FracCircle
{
public:
	FracCircle();
	FracCircle(float x, float y, float r);

	void drawCircle(float y, ofColor color);

private:
	float xPos;
	float yPos;
	float radius;
};

