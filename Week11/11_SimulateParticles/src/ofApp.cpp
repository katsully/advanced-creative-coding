#include "ofApp.h"

Particle* particles;
bool saving = false;



//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofEnableSmoothing();
	ofEnableAlphaBlending();

	particles = new Particle[1000];
	for (int i = 0; i < 1000; i++) {
		particles[i] = Particle(ofPoint(100, ofGetHeight() - 100));
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(255, 255, 255);
	ofSetColor(0, 0, 0);
	for (int i = 0; i < 1000; i++) {
		particles[i].update();
		particles[i].draw();
	}
}