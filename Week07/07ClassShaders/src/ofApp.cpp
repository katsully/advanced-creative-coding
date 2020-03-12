#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// loads a shader from .vert file and .frag file
	shader.load("shadersGL3/shader");

	int planeWidth = ofGetWidth() * .75;
	int planeHeight = ofGetHeight() * .75;
	int planeGridSize = 20;
	int planeColumns = planeWidth / planeGridSize;
	int planeRows = planeHeight / planeGridSize;

	plane.set(planeWidth, planeHeight, planeColumns, planeRows,
		OF_PRIMITIVE_TRIANGLES);

	cone.set(100, 100, 20, 20);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);

	float percentX = mouseX / (float)ofGetWidth();
	// clamps a value between the given min and max
	percentX = ofClamp(percentX, 0, 1);

	// the position of the mouse (x-dir) will change the color!
	ofColor colorLeft = ofColor::magenta;
	ofColor colorRight = ofColor::cyan;
	ofColor lerpedColor = colorLeft.getLerped(colorRight, percentX);
	ofSetColor(lerpedColor);

	shader.begin();

	shader.setUniform1f("time", ofGetElapsedTimef());

	float translateX = ofGetWidth() / 2;
	float translateY = ofGetHeight() / 2;
	ofTranslate(translateX, translateY);

	plane.drawWireframe();
	if (ofGetElapsedTimef() > 2.0f && ofGetElapsedTimef() < 5.0f) {
		cone.drawWireframe();
	}
	
	shader.end();
}

