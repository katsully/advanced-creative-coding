#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1000, 1000);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(0, 255, 0);
	ofDrawTriangle(x1, y1, x2, y2, x3, y3);

	// x1 reaches the threshold (either so large it's about to go off the canvas or so small it's about to be invisible swith increase
	// if the scale was increasing, decrease, if it was decreasing, increase
	if (x1 < 1 || x1 > 450) {
		increase = !increase;
	}

	
	if (increase) {
		// ++x increments x and returns the incremented number, whereas x++ returns x and then increments it.
		// ++x is faster if you are doing it on a single line, since ++x doesn't have to a create a temporary.
		--x1;
		++y1;
		--y2;
		++x3;
		++y3;
	}
	else {
		++x1;
		--y1;
		++y2;
		--x3;
		--y3;
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
