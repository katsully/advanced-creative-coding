#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	// how spread apart the circle in a circular formation will be
	radius = 100;
	xOffset = ofGetWidth() / 2;
	yOffset = ofGetHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);
	a = 0;
	// for drawing circle in a circular formation
	for (int i = 0; i < 30; i++) {
		ofDrawCircle(radius * sin(a) + xOffset, radius * cos(a) + yOffset, 25);
		a += stepSize;
	}
	// if you offset where the x starts, it will 'snake'
	/*float x = 0;
	for (int i = 0; i < 100; i++) {
		ofDrawCircle(x, sin(x-xStart) * 100 + ofGetHeight() / 2, 15);
		x+=25;
	}
	xStart+=.01;*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
