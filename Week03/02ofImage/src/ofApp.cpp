#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1000, 1000);
	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (Landscape l : pics) {
		l.draw();
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	pics.push_back(Landscape(x, y));
}

