#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableAlphaBlending();

	csv.load("Z_Solo_Best.csv");
	row = 6;

	numCols = csv.getNumCols();

	for (int i = row; i < csv.getNumRows(); i+=3) {
		for (int col = 2; col < numCols; col += 3) {
			if (ofToFloat(csv[i][col]) < xMin) {
				xMin = ofToFloat(csv[i][col]);
			}
			if (ofToFloat(csv[i][col]) > xMax) {
				xMax = ofToFloat(csv[i][col]);
			}
			if (ofToFloat(csv[i][col + 1]) < yMin) {
				yMin = ofToFloat(csv[i][col + 1]);
			}
			if (ofToFloat(csv[i][col + 1]) > yMax) {
				yMax = ofToFloat(csv[i][col + 1]);
			}
		}
	}

	ofSetFrameRate(30);

}

//--------------------------------------------------------------
void ofApp::update(){
	int counter = 0;
	for (int col = 2; col < numCols; col += 3) {
		if (start) {
			positions.push_back(ofVec2f(ofToFloat(csv[row][col]), ofToFloat(csv[row][col + 1])));
			velocities.push_back(ofVec2f(0, 0));
			accelerations.push_back(ofVec2f(0, 0));
		}
		else {
			ofVec2f currPos = ofVec2f(ofToFloat(csv[row][col]), ofToFloat(csv[row][col + 1]));
			// previous position - curr position
			ofVec2f currVel = positions[counter] - currPos;
			// previous vel - curr vel
			ofVec2f currAcc = velocities[counter] - currVel;
			positions[counter] = currPos;
			velocities[counter] = currVel;
			accelerations[counter] = currAcc;
		}
		++counter;
	}


	// an element pointed by iterator iter is removed from the vector, elements are shifted in memory in order to fill that gap which invalidates iter. 
	// iter gets a new value and now points to the first element after the the removed one or the end of the vector (if removed element was the last one). 
	// This means that after erasing an element you should not advance iter
	if (start == false) {
		for (vector<Trail*>::iterator iter = trails.begin(); iter != trails.end();)
		{
				if ((*iter)->update() == false)
				{
					iter = trails.erase(iter);
				}
				else
				{
					++iter;
				}
		}
	}
	
	if (row == 6) {
		start = false;
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);
	// ofSetColor(255, 0, 0);
	
	for (int i = 0; i < positions.size(); i++) {
		ofColor color = ofColor::fromHsb(abs(velocities[i].length()), 255, 255);
		ofSetColor(color);

		//ofDrawCircle(ofMap(positions[i].x, xMin, xMax, 0, ofGetWidth()), ofMap(positions[i].y, yMax, yMin, 0, ofGetHeight()), abs(accelerations[i].length()));

		trails.push_back(new Trail(ofMap(positions[i].x, xMin, xMax, 0, ofGetWidth()), ofMap(positions[i].y, yMax, yMin, 0, ofGetHeight()), color, abs(accelerations[i].length())));
	}
	for (int i = 0; i < trails.size(); i++) {
		trails[i]->display();
	}
	if (row < csv.getNumRows()) {
		row++;
	}
	else {
		ofExit();
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
