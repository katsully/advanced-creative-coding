#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bool isRunning;
	int counter;
	float decimalNumber;
	ofVec2f coords;
	
	ofFile file;

	file.open(ofToDataPath("MyParams.json"), ofFile::ReadWrite, false);
	if (file.exists()) {
		ofJson json = ofLoadJson(file);
		cout << file << endl;
		
		if (json["boolVariable"].is_null() == false) isRunning = json["boolVariable"];
		if (json["intValue"].is_null() == false) counter = json["intValue"];
		if (json["floatValue"].is_null() == false) decimalNumber = json["floatValue"];
		if (json["xyCoords"].is_null() == false) coords = ofVec2f(json["xyCoords"]["xPos"], json["xyCoords"]["yPos"]);

		cout << isRunning << endl;
		cout << counter << endl;
		cout << decimalNumber << endl;
		cout << coords << endl;

	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
