#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.setup(640, 480);
	
	color.allocate(camera.getWidth(), camera.getHeight());
	gray.allocate(camera.getWidth(), camera.getHeight());

	haar.setup("haarcascade_frontalface_default.xml");
	
	haar.setScaleHaar(2);

	newTexture.allocate(camera.getWidth(), camera.getHeight(), GL_RGB);
	newPixels = new unsigned char[640 * 480 * 3];

	receiver.setup(7004);

	sender.init("My sender");
	myTexture.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
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

	/*while (receiver.hasWaitingMessages()) {
		ofxOscMessage rMsg;
		receiver.getNextMessage(rMsg);
		if (rMsg.getAddress() == "/1/fader1") {
			float c = ofMap(rMsg.getArgAsFloat(0), 0, 1, 0, 360);
			tint = ofColor::fromHsb(c, 100, 100);
		}
	}*/

	while (receiver.hasWaitingMessages()) {
		ofxOscMessage rMsg;
		receiver.getNextMessage(rMsg);
		if (rMsg.getAddress() == "/2/push1") {
			superFace = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	// camera.draw(0, 0);

	//gray.draw(0, 0);

	// color.draw(0, 0);
	

	for (int i = 0; i < haar.blobs.size(); i++) {
		/*ofSetColor(255);
		ofNoFill();
		ofDrawRectangle(haar.blobs[i].boundingRect);*/
		ofRectangle rect;
		rect = haar.blobs[i].boundingRect;

		/*for (int x = rect.x; x < rect.getMaxX(); x++) {
			for (int y = rect.y; y < rect.getMaxY(); y++) {
				unsigned char r, g, b;
				getPixel(x, y, &r, &g, &b, 640, color.getPixels());
				setPixel(x, y, r, g, b, 640, color.getPixels().getData());
			}
		}*/

		
		ofPixels myFace = color.getPixels();
		myFace.crop(rect.x, rect.y, rect.width, rect.height);
		ofTexture tex;
		tex.allocate(rect.width, rect.height, GL_RGB);
		tex.loadData(myFace);

		// faces.push_back(new Face(tex, rect.x + 100, rect.y + 100, tint));

		if (superFace) {
			faces.clear();
			float a = 0;
			float radius = 25;
			for (int i = 0; i < 20; i++) {
				faces.push_back(new Face(tex, radius * sin(a) + rect.x, radius * cos(a) + rect.y, ofColor::white));
				a += .2;
				radius += 15;
			}
			superFace = false;
		}
		
	}
	ofSetColor(ofColor::white);
	color.draw(0, 0);
	for (int i = 0; i < faces.size(); i++) {
		faces[i]->display();
	}

	myTexture.loadScreenData(0, 0, ofGetWidth(), ofGetHeight());

	sender.send(myTexture);

	
}

//--------------------------------------------------------------
void ofApp::setPixel(int horizontal, int vertical, unsigned char R,
	unsigned char G, unsigned char B, int w, unsigned char pixels[]) {

	// the single pixel from the texture that i'm currently drawing to
	int thisPixel;
	thisPixel = 3 * (w * vertical + horizontal);
	pixels[thisPixel] = G;
	pixels[thisPixel + 1] = B;
	pixels[thisPixel + 2] = R;
}

//--------------------------------------------------------------
void ofApp::getPixel(int horizontal, int vertical, unsigned char* R, unsigned char* G, unsigned char* B, int w,
	ofPixels pixels) {

	 
	// the single pixel where i'm extracting the r, g, and b values
	int thisPixel;
	thisPixel = 3 * (w * vertical + horizontal);
	*R = pixels[thisPixel];
	*G = pixels[thisPixel + 1];
	*B = pixels[thisPixel + 2];

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
