#include "ofApp.h"

ofImage img;

enum ColorState {
	RED,
	YELLOW,
	GREEN
};

ColorState myColorState;

//--------------------------------------------------------------
void ofApp::setup(){
	button.addListener(this, &ofApp::changeBackgroundColor);

	// setting up our panel
	gui.setup("Our Parameters!");
	// 1st parameter - name
	// 2nd parameter - default value
	// 3rd parameter  - min value
	// 4th parameter - max value
	gui.add(slider.set("Radius", 100, 12, ofGetWidth() / 2));
	gui.add(colorChoice.set("Color", ofColor(255, 0, 0), ofColor(0), ofColor(255)));
	gui.add(button.setup("Change it!"));
	gui.add(toggle.set("Now you see it", true));
	gui.add(circleRes.set("Circle Res", 100, 2, 100));
	gui.add(screenShot.set("Screenshot"));
	gui.add(multiples.setup("Multiples", 0, 0, 10));
	gui.add(origin.set("Origin", ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	
	
	myColorState = ColorState::RED;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetCircleResolution(circleRes);

	switch (myColorState)
	{
	case RED:
		ofSetBackgroundColor(ofColor(255, 0, 0));
		break;
	case YELLOW:
		ofSetBackgroundColor(ofColor(255, 255, 0));
		break;
	case GREEN:
		ofSetBackgroundColor(ofColor(0, 255, 0));
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (toggle) {
		//ofSetBackgroundColor(backgroundColor);
		ofSetColor(colorChoice);
		ofDrawCircle(origin->x, origin->y, slider);

		for (int i = 0; i < multiples; i++) {
			ofDrawCircle(origin->x + (i * 10), origin->y + (i * 10), slider);
		}

	}

	
	if (drawGui) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		drawGui = !drawGui;
	}
	else if (key == 's') {
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		img.save(screenShot.toString() + ".png");
	}
}

void ofApp::changeBackgroundColor() {
	backgroundColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
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
