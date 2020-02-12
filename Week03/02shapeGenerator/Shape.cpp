#include "Shape.h"



Shape::Shape()
{	
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	xPos = 300;
	yPos = 300;
	scale = 200;
	increase = true;
	// shape = "rectangle";
}

Shape::Shape(int x, int y)
{
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	scale = 200;
	increase = true;
	xPos = x;
	yPos = y;
}

void Shape::update() {
	if (scale < 10 || scale > 450) {
		increase = !increase;
	}

	if (increase) {
		// ++x increments x and returns the incremented number, whereas x++ returns x and then increments it.
		// ++x is faster if you are doing it on a single line, since ++x doesn't have to a create a temporary.
		++scale;
	}
	else {
		--scale;
	}
}


void Shape::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofTranslate(xPos, yPos);
	ofRotateZ(ofGetElapsedTimef() * 10);
	ofSetColor(color);
	ofDrawRectangle(0, 0, scale, scale);
	ofPopMatrix();
}



Shape::~Shape()
{
}
