#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(500, 500);
	ofSetFrameRate(30);

	ofSetLineWidth(10);
	// disable oF from automatically drawing over the background (ie prevent animations)
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(100, 100);

	// determines how much you offset from the original value to the next value (ie the smaller the number the smoother the transition, the larger the number, the more 'jittery' it gets)
	xoff += .025;
	// generate the perlin noise value
	float n =  ofNoise(xoff) * 200;
		
	ofLine(n, 200, n, 400);

	ofSetColor(175, 100);

	xoff2 = xoff2 + .05;
	float n2 = ofNoise(xoff2) * 250;

	ofLine(n2, 200, n2, 400);

	
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
