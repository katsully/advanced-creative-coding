#include "ofApp.h"
float angle = 0;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);
	
	ofNoFill();

	drawFractalCircle(ofGetWidth() / 2, ofGetHeight() / 2, 300);
	
	// hue - color
	// 2nd parameter saturation
	// 3rd parameter brightness
	color = ofColor::fromHsb(hue, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){
	startAngle += 0.015;
	angle = startAngle;

	// slow increment - chill vibes
	// fast increment - buggin
	hue += .1;
	if(hue >= 255) {
		hue = 0;
	}
	color.setHue(hue);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	// pros of using iterators, it allows flexibilty
	// all containers have iterators
	// another pro with iterators : it advance(2)
	for (vector<FracCircle*>::iterator it = circles.begin(); it != circles.end(); ++it) {
		// ofMap 
		// 1st - the value
		// 2nd & 3rd - the low and high of the range of sin(x)
		// 4th & 5th - desired range
		float y = ofMap(sin(angle), -1, 1, 0, float(ofGetWindowHeight()));

		// the * gives the item referenced by the pointer (the pointer)
		// -> derefernces the pointer (giving us the actual FracCircle
		(*it)->drawCircle(y, color);
		angle += angleVar;
	}
	
	//drawFractalCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 300);
}

void ofApp::drawFractalCircle(float x, float y, float radius) {
	//ofDrawCircle(x, y, radius);

	circles.push_back(new FracCircle(x, y, radius));

	if (radius > 2) {
		// left circle
		drawFractalCircle(x + radius / 2.0f, y, radius / 2.0f);
		// right circle
		drawFractalCircle(x - radius / 2.0f, y, radius / 2.0f);
		// upper circle
		//drawFractalCircle(x, y - radius / 2, radius / 2);
		// lower circle
		//drawFractalCircle(x, y + radius / 2, radius / 2);
	}
}

