#include "ofApp.h"
#include "../apps/myApps/03class/Shape.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1000, 1000);
	x = 0;
	y = 0;
	ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void ofApp::update(){
	// post incrementing - less efficent
	// post makes a copy of the variable, THEN increments
	// x++;

	// pre incrementing - MORE efficent
	// don't have to create a temp
	++x;
	++y;
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (Shape s : shapes) {
		s.draw();
	}
}

void ofApp::mousePressed(int x, int y, int button) {
	// x and y values are where the mouse was pressed
	shapes.push_back(Shape(x, y));
}

void ofApp::mouseDragged(int x, int y, int button) {
	// x and y values are where the mouse was pressed
	shapes.push_back(Shape(x, y));
}

void ofApp::keyPressed(int key) {
	// FIXED
	// was passing by value, not by reference, will go over this in class
	// note the & before the s on line 47
	for (Shape &s : shapes) {
		s.setRotationValue(10);
	}
	
}

