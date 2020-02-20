#include "ofApp.h"

// width and height of your image
int values[1024][683];

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofNoFill();
	angle = 0.0f;

	img.loadImage("glacier.jpg");
	ofPixels pixels = img.getPixels();
	for (int i = 0; i < 683; i++) {
		for (int j = 0; j < 1024; j++) {
			values[j][i] = pixels[(int)(i * 1024 + j)];
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotate(ofRadToDeg(angle), 0, 1, 0);
	ofScale(2, 2, 2);

	angle += 0.005f;

	glBegin(GL_LINES);
	for (int i = 0; i < 683; i += 3) {
		for (int j = 0; j < 1024; j += 3) {
			float val = (float)values[j][i];
			ofSetColor(val, val, val, 153);
			float x1 = j - 1024 / 2;
			float y1 = i - 683 / 2;
			float z1 = -val / 2;
			float x2 = j - 1024 / 2;
			float y2 = i - 683 / 2;
			float z2 = -val / 2 - 4;

			glVertex3f(x1, y1, z1);
			glVertex3f(x2, y2, z2);
		}
	}
	glEnd();
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
