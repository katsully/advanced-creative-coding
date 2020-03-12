#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// loads a shader from a .vert file and a .frag file
	shader.load("shadersGL3/shader");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);

	// begin and end tell the renderer to have vertices and texutres go through a shader
	// rather than being passed directly to the framebuffer
	// start using your shader to alter all the drawing that your application is doing
	shader.begin();

	shader.setUniform1f("windowWidth", ofGetWindowWidth());
	shader.setUniform1f("windowHeight", ofGetWindowHeight());
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	// stop using your shader to alter all the drawing that your application is doing
	shader.end();
}

