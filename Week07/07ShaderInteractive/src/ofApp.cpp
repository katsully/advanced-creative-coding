#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load("shadersGL3/shader");

	int planeWidth = ofGetWidth();
	int planeHeight = ofGetHeight();
	int planeGridSize = 20;
	int planeColums = planeWidth / planeGridSize;
	int planeRows = planeHeight / planeGridSize;

	plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();

	// center screen
	float cx = ofGetWidth() / 2.0;
	float cy = ofGetHeight() / 2.0;

	// the plane is being positioned in the middle of the screen
	// so we have to apply the same offset to the mouse coordinates before passing into the shader
	float mx = mouseX - cx;
	float my = mouseY - cy;

	// we can pass in a single value into the shader by using the setUniform1 function
	// float - setUniform1f
	// int - setUniform1s
	shader.setUniform1f("mouseRange", 300);

	// we can pass in two values into the shader at the same time by using the
	// setUniform2 function
	// insude the shader these two values are set inside a vec2 object
	shader.setUniform2f("mousePos", mx, my);

	// color changes from magenta to blue when moving the mouse from left to right
	float percentX = mouseX / (float)ofGetWidth();
	percentX = ofClamp(percentX, 0, 1);
	ofFloatColor colorLeft = ofColor::red;
	ofFloatColor colorRight = ofColor::green;
	ofFloatColor colorMix = colorLeft.getLerped(colorRight, percentX);

	// create a float array with color values
	float mouseColor[4] = { colorMix.r, colorMix.g, colorMix.b, colorMix.a };

	// we can pass in four values into the shader at the same time as a float array
	// we do this by passing a pointer reference to the first element in the array
	// inside the shader these four values are set inside a vec4 object
	shader.setUniform4fv("mouseColor", mouseColor);

	ofTranslate(cx, cy);
	plane.drawWireframe();

	shader.end();
}