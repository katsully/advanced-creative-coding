#include "ofApp.h"

// the width and height of your video file
int video_width = 640;
int video_height = 360;
int video_slice_x = video_width / 2;
int window_width = 1000;
int window_height = video_height;
int draw_position_x = 0;


//--------------------------------------------------------------
void ofApp::setup(){
	player.load("video.mp4");
	player.setLoopState(OF_LOOP_NORMAL);
	player.play();

	ofSetWindowShape(window_width, window_height);

	// make empty canvas for us to draw beautiful slit scans
	texture.allocate(window_width, window_height, GL_RGB);
	texpixels = new unsigned char[window_width * window_height * 3];
}

//--------------------------------------------------------------
void ofApp::update() {
	// get all new frames
	player.update();
	player.getCurrentFrame();
	if (player.isFrameNew()) {
		vidpixels = player.getPixels();
		for (int y = 0; y < window_height; y++) {
			unsigned char r, g, b;
			getPixel(video_slice_x, y, &r, &g, &b, video_width, vidpixels);
			setPixel(draw_position_x, y, r, g, b, window_width, texpixels);
		}
		texture.loadData(texpixels, window_width, window_height, GL_RGB);

		++draw_position_x;
		if (draw_position_x >= window_width) {
			OF_EXIT_APP(0);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);
	texture.draw(0, 0);
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

