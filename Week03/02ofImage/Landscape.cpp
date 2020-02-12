#include "Landscape.h"



Landscape::Landscape()
{
	pic.load("download.jpg");
	startingX = 100;
	startingY = 100;
	rotationValue = 10;
}

Landscape::Landscape(int x, int y)
{
	pic.load("download.jpg");
	startingX = x;
	startingY = y;
	rotationValue = ofRandom(50);
}

void Landscape::draw() {
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofTranslate(startingX, startingY);
	ofRotateZ(ofGetElapsedTimef() * rotationValue);
	pic.draw(0, 0, 300, 168);
	ofPopMatrix();
}


Landscape::~Landscape()
{
}
