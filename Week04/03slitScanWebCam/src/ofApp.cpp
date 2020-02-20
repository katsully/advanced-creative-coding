#include "ofApp.h"

int window_width = 1000;
int draw_position_x = 0;
int camWidth = 320;
int camHeight = 240;
int video_slice_x = camWidth / 2;
int window_height = camHeight;

//--------------------------------------------------------------
void ofApp::setup() {
	vector<ofVideoDevice> devices = vidGrabber.listDevices();

	for (int i = 0; i < devices.size(); i++) {
		if (devices[i].bAvailable) {
			//log the device
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
		}
		else {
			//log the device and note it as unavailable
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
		}
	}

	ofSetWindowShape(window_width, window_height);

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);

	// make empty canvas for us to draw beautiful slit scans
	videoTexture.allocate(window_width, window_height, GL_RGB);
	texpixels = new unsigned char[window_width * window_height * 3];
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update() {
	// get all new frames
	vidGrabber.update();
	if (vidGrabber.isFrameNew()) {
		vidpixels = vidGrabber.getPixels();
		for (int y = 0; y < camHeight; y++) {
			unsigned char r, g, b;
			getPixel(video_slice_x, y, &r, &g, &b, camWidth, vidpixels);
			setPixel(draw_position_x, y, r, g, b, window_width, texpixels);
		}
		videoTexture.loadData(texpixels, window_width, window_height, GL_RGB);

		++draw_position_x;
		if (draw_position_x >= window_width) {
			// OF_EXIT_APP(0);
			draw_position_x = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0, 0, 0);
	videoTexture.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::setPixel(int horizontal, int vertical, unsigned char R,
	unsigned char G, unsigned char B, int w, unsigned char pixels[]) {

	// the single pixel where i'm extracting the r, g, and b values
	int thisPixel;
	thisPixel = 3 * (w * vertical + horizontal);
	pixels[thisPixel] = R;
	pixels[thisPixel + 1] = G;
	pixels[thisPixel + 2] = B;
}

//--------------------------------------------------------------
void ofApp::getPixel(int horizontal, int vertical, unsigned char* R, unsigned char* G, unsigned char* B, int w,
	ofPixels pixels) {

	// the single pixel from the texture that i'm currently drawing to 
	int thisPixel;
	thisPixel = 3 * (w * vertical + horizontal);
	*R = pixels[thisPixel];
	*G = pixels[thisPixel + 1];
	*B = pixels[thisPixel + 2];

}

