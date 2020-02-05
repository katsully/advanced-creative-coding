#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1000, 1000);
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	int x1 = 0;
	int y1 = 0;
	int x2 = -50;
	int y2 = 100;
	int x3 = 50;
	int y3 = 100;

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 20; j++) {
			// draw the triangles for column j
			ofFill();
			ofSetColor(2500);
			ofDrawTriangle(x1, y1+j*100, x2, y2+j*100, x3, y3+j*100);
			ofNoFill();
			ofSetColor(0);
			ofDrawTriangle(x1, y1+j*100, x2, y2+j*100, x3, y3+j*100);
		}

		// increment the variables (ie shift over the triangles)
		if (i % 3 == 0) {
			x2 += 150;
			if (i % 2 == 0) {
				y2 -= 100;
			}
			else {
				y2 += 100;
			}
			
		}
		else if (i % 3 == 1) {
			x1 += 150;
			if (i % 2 == 0) {
				y1 -= 100;
			}
			else {
				y1 += 100;
			}
		}
		else {
			x3 += 150;
			if (i % 2 == 0) {
				y3 -= 100;
			}
			else {
				y3 += 100;
			}
		}
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
