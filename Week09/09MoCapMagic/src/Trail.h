#include "ofMain.h"

#pragma once
class Trail
{
public:
	Trail();
	Trail(float x, float y, ofColor c, int r);
	bool update();
	void display();

	ofVec2f position;
	ofColor color;
	int transparency = 255;
	int radius;
};

