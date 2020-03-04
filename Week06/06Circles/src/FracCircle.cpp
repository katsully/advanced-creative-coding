#include "FracCircle.h"

FracCircle::FracCircle() {
	xPos = 0;
	yPos = 0;
	radius = 10;
}

FracCircle::FracCircle(float x, float y, float r) {
	xPos = x;
	yPos = y;
	radius = r;
}

void FracCircle::drawCircle(float y, ofColor color) {
	ofSetColor(color);
	ofDrawCircle(xPos, y, radius);
}
