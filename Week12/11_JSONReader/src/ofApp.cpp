#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bool mesh;
	int limit;
	
	ofFile file;

	file.open(ofToDataPath("MyParams.json"), ofFile::ReadWrite, false);
	if (file.exists()) {
		ofJson json = ofLoadJson(file);
		cout << file << endl;
		
		if (json["drawMesh"].is_null() == false) mesh = json["drawMesh"];
		if (json["mFarLimit"].is_null() == false) limit = json["mFarLimit"];

		cout << mesh << endl;
		cout << limit << endl;


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
