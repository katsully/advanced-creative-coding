#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(640, 480);
	camera.setup(640, 480);

	color.allocate(camera.getWidth(), camera.getHeight());
	gray.allocate(camera.getWidth(), camera.getHeight());

	haar.setup("haarcascade_frontalface_default.xml");

	haar.setScaleHaar(2);

	receiver.setup(7004);
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();

	if (camera.isFrameNew()) {
		color.setFromPixels(camera.getPixels());
		gray = color;
		// finding faces in the pixels
		haar.findHaarObjects(gray);
	}

	while (receiver.hasWaitingMessages()) {
		ofxOscMessage rMsg;
		receiver.getNextMessage(rMsg);
		// address from TouchOSC
		if (rMsg.getAddress() == "/2/push1") {
			superFace = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < haar.blobs.size(); i++) {
		ofRectangle rect;
		rect = haar.blobs[i].boundingRect;

		ofPixels myFace = color.getPixels();
		myFace.crop(rect.x, rect.y, rect.width, rect.height);
		ofTexture tex;
		tex.allocate(rect.width, rect.height, GL_RGB);
		tex.loadData(myFace);

		// if we get OSC message, spiral out the face
		if (superFace) {
			faces.clear();
			float a = 0;
			float radius = 25;
			for (int i = 0; i < 20; i++) {
				faces.push_back(new Face(tex, radius * sin(a) + rect.x, radius * cos(a) + rect.y));
				a += .2;
				radius += 15;
			}
			// prevent duplicated messages
			superFace = false;
		}

	}
	ofSetColor(ofColor::white);
	color.draw(0, 0);
	for (int i = 0; i < faces.size(); i++) {
		faces[i]->display();
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
