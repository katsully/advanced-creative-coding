#pragma once

#include "ofMain.h"

class KochLine
{
private:
	ofVec2f start;
	ofVec2f end;
public:
	KochLine();
	KochLine(ofVec2f a, ofVec2f b);

	void display();
	ofVec2f getPointA();
	ofVec2f getPointB();
	ofVec2f getPointC();
	ofVec2f getPointD();
	ofVec2f getPointE();
};

