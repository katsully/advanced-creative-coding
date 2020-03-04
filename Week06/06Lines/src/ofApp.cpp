#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// left side of the screen
	ofVec2f left = ofVec2f(0, ofGetWindowHeight() / 2);
	// right side of the screen
	ofVec2f right = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight() / 2);

	lines.push_back(new KochLine(left, right));
	ofSetColor(ofColor::wheat);

	for (int i = 0; i < 7; i++) {
		generate();
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	for (vector<KochLine*>::iterator it = lines.begin(); it != lines.end(); ++it) {
		(*it)->display();
	}
}

void ofApp::generate() {
	vector<KochLine*> next;

	//for every current line
	for (vector<KochLine*>::iterator it = lines.begin(); it != lines.end(); ++it) {
		ofVec2f a = (*it)->getPointA();
		ofVec2f b = (*it)->getPointB();
		ofVec2f c = (*it)->getPointC();
		ofVec2f d = (*it)->getPointD();
		ofVec2f e = (*it)->getPointE();

		next.push_back(new KochLine(a, b));
		next.push_back(new KochLine(b, c));
		next.push_back(new KochLine(c, d));
		next.push_back(new KochLine(d, e));

	}

	lines = next;
}