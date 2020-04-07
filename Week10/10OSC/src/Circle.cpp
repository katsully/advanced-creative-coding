#include "Circle.h"


Circle::Circle()
{
	position = ofVec2f(ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()));
}

Circle::Circle(ofColor c)
{
	color = c;
	position = ofVec2f(ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()));
}

void Circle::display()
{
	ofSetColor(color);
	ofDrawCircle(position, 15);
}