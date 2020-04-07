#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//sender.setup("localhost", 12345);
	receiver.setup(12345);
}

//--------------------------------------------------------------
void ofApp::update(){
	/*timeSent = ofGetElapsedTimef();
	ofxOscMessage message;
	message.setAddress("/time");
	message.addFloatArg(timeSent);
	sender.sendMessage(message);*/

	// while oscReceiver has incoming non-processed messages
	/*while (receiver.hasWaitingMessages()) {
		ofxOscMessage rMsg;
		receiver.getNextMessage(rMsg);
		if (rMsg.getAddress() == "/time") {
			timeReceived = rMsg.getArgAsFloat(0);
		}
	}*/

	while (receiver.hasWaitingMessages()) {
		ofxOscMessage rMsg;
		receiver.getNextMessage(rMsg);
		if (rMsg.getAddress() == "/new") {
			/*if (rMsg.getArgAsBool(0)) {
				circles.push_back(new Circle());
			} */
			if (rMsg.getArgAsString(0) == "red") {
				circles.push_back(new Circle(ofColor::red));
			}
			else if (rMsg.getArgAsString(0) == "green") {
				circles.push_back(new Circle(ofColor::green));
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	//ofDrawBitmapStringHighlight("Time Sent: " + ofToString(timeSent, 3), 50, 50);

	//ofDrawBitmapStringHighlight("Time Received: " + ofToString(timeReceived, 3), 50, 70);
	//ofDrawBitmapStringHighlight("Time Sent - Time Received: " + ofToString(timeSent - timeReceived, 3), 50, 90);

	for (int i = 0; i < circles.size(); i++) {
		circles[i]->display();
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
