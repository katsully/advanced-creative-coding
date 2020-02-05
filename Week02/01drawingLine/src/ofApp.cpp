#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// set window resolution to 1000 pixels by 1000 pixels
	ofSetWindowShape(1000, 1000);
	
	// set frame rate to 30 frames per second 
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	int color = 10;
	float x1 = 10;
	float y1 = 200;
	float x2 = 10;
	float y2 = 800;

	ofSetLineWidth(10);

	
	for (int i = 0; i < 50; i++) {
		ofSetColor(color);
		ofLine(x1, y1, x2, y2);

		x1 += 20;
		x2 += 20;
		color += 8;
	}

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
