#include "Shape.h"



Shape::Shape()
{
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = ofRandom(500);
	startingY = 100;
	width = 50;
	height = 50;
	rotationValue = 10;
}

Shape::Shape(int x, int y) {
	startingX = x;
	startingY = y;
	width = 50;
	height = 50;
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	rotationValue = ofRandom(100);
}

Shape::~Shape()
{
}

void Shape::draw() {
	ofSetColor(color);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofTranslate(startingX, startingY);
	ofRotateZ(ofGetElapsedTimef() * rotationValue);
	ofDrawRectangle(0, 0, width, height);
	ofPopMatrix();
}

void Shape::setRotationValue(int r) {
	rotationValue = r;
}
