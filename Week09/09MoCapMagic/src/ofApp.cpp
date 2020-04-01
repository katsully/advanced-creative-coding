#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	csv.load("Z_Solo_Best.csv");

	for (int i = 7; i < csv.getNumRows(); i++) {
		for (int j = 2; j < csv.getNumCols(); j += 3) {
			// very first time, initialize values
			if (i == 7 && j == 2) {
				xMin = ofToFloat(csv[i][j]);
				xMax = ofToFloat(csv[i][j]);
				yMin = ofToFloat(csv[i][j + 1]);
				yMax = ofToFloat(csv[i][j + 1]);
			}
			else {
				if (ofToFloat(csv[i][j]) < xMin) {
					xMin = ofToFloat(csv[i][j]);
				}
				if (ofToFloat(csv[i][j]) > xMax) {
					xMax = ofToFloat(csv[i][j]);
				}
				if (ofToFloat(csv[i][j + 1]) < yMin) {
					yMin = ofToFloat(csv[i][j + 1]);
				}
				if (ofToFloat(csv[i][j]) > yMax) {
					yMax = ofToFloat(csv[i][j + 1]);
				}
			}
		}
	}

	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
	int markerIdx = 0;
	for (int j = 2; j < csv.getNumCols(); j += 3) {
		if (row == 7) {
			positions.push_back(ofVec2f(ofMap(ofToFloat(csv[row][j]), xMin, xMax, 0, ofGetWindowWidth()), ofMap(ofToFloat(csv[row][j + 1]), yMax, yMin, 0, ofGetWindowHeight()) ));
			velocities.push_back(ofVec2f::zero());
			accelerations.push_back(ofVec2f::zero());
		}
		else {
			// curr position
			// ofVec2f currPos = ofVec2f(ofToFloat(csv[row][j]), ofToFloat(csv[row][j + 1]));
			ofVec2f currPos = ofVec2f(ofMap( ofToFloat(csv[row][j]), xMin, xMax, 0, ofGetWindowWidth() ), ofMap( ofToFloat(csv[row][j+1]), yMax, yMin, 0, ofGetWindowHeight()) );
			// vel = curr Pos - prev pos
			// positions vector represents the PREVIOUS frame of positions
			ofVec2f currVel = currPos - positions[markerIdx];
			// acceleration = curr vel - prev vel
			ofVec2f currAcc = currVel - velocities[markerIdx];
			
			positions[markerIdx] = currPos;
			velocities[markerIdx] = currVel;
			accelerations[markerIdx] = currAcc;
		}
		++markerIdx;
	}

	//for (vector<Trail*>::iterator iter = trails.begin(); iter != trails.end();) {
	//	// if update returns false, the trail is transparent, remove it
	//	if ((*iter)->update() == false) {
	//		iter = trails.erase(iter);
	//	}
	//	// move the iter over
	//	else {
	//		++iter;
	//	}
	//}

	for (int i = 0; i < particles.size(); i++ ) {
		// move the particle
		particles[i]->update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(5);
	// uniform color
	// ofSetColor(255, 0, 0);
	for (int i = 0; i < positions.size(); i++) {
		// uniform radius
		//ofDrawCircle(ofMap(ofToFloat(csv[row][j]), xMin, xMax, 0, ofGetWindowWidth()), ofMap(ofToFloat(csv[row][j + 1]), yMax, yMin, 0, ofGetWindowHeight()), 10);

		// dyanmic color
		ofColor tempColor = ofColor::fromHsb(abs(accelerations[i].length()) * 2.0, 255, 255);
		// ofSetColor(tempColor);

		// dynamic radius
		//ofDrawCircle(ofMap(positions[i].x, xMin, xMax, 0, ofGetWindowWidth()), ofMap(positions[i].y, yMax, yMin, 0, ofGetWindowHeight()), abs(accelerations[i].length()));

		// position already mapped
		ofDrawCircle(positions[i], 10);

		// trails
		//trails.push_back(new Trail( ofMap( positions[i].x, xMin, xMax, 0, ofGetWindowWidth() )  , ofMap( positions[i].y, yMax, yMin, 0, ofGetWindowHeight() ), tempColor, abs(accelerations[i].length())));
	}

	/*for (int i = 0; i < trails.size(); i++) {
		trails[i]->display();
	}*/

	// draw particles
	for (int i = 0; i < particles.size(); i++) {
		// move the particle
		particles[i]->display();
	}

	if (row < csv.getNumRows()) {
		++row;
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
	// positions is a vector of positions for each marker at this current frame
	// positions[15] represents the positition of the left hand
	particles.push_back(new Particle(positions[15], velocities[15], accelerations[15]));
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
