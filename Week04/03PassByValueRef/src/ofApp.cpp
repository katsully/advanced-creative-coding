#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// load image of the icon
	// we use a dot here because 'image' is
	// the image itself, and not a pointer
	image.loadImage("Twitter.png");

	// create the smiles
	for (int i = 0; i < 500; i++) {
		smiles.push_back(new TestImg());
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < smiles.size(); i++) {
		// we use an arrow here, because smiles[i] is a pointer,   
		//  not the instance of the smile itself  
		// smiles[i]->draw(image);

		// & means address of
		smiles[i]->draw(&image);
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
