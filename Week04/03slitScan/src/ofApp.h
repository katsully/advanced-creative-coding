#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		// signed char, which gives you at least the -127 to 127 range. (-128 to 127 is common)
		// unsigned char, which gives you at least the 0 to 255 range.
		void setPixel(int horizontal, int vertical, unsigned char R,
			unsigned char G, unsigned char B, int w, unsigned char pixels[]);
		void getPixel(int horizontal, int vertical, unsigned char* R, unsigned char* G, unsigned char* B, int w,
			ofPixels pixels);

		ofVideoPlayer player;
		ofTexture texture;
		unsigned char * texpixels;
		ofPixels vidpixels;

};
