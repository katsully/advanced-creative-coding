#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "Face.h"

#include "ofxOsc.h"	

#include "ofxSpout.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void getPixel(int horizontal, int vertical, unsigned char* R, unsigned char* G, unsigned char* B, int w,
			ofPixels pixels);
		void setPixel(int horizontal, int vertical, unsigned char R,
			unsigned char G, unsigned char B, int w, unsigned char pixels[]);

		ofVideoGrabber camera;
		
		ofxCvColorImage color;
		ofxCvGrayscaleImage gray;
		ofxCvHaarFinder haar;

		unsigned char * newPixels;
		ofTexture newTexture;

		vector<Face*> faces;


		ofxOscReceiver receiver;
		ofColor tint;

		bool superFace = false;

		ofxSpout::Sender sender;
		ofTexture myTexture;
		
};
