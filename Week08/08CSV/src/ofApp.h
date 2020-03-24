#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "Subway.h"

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

		ofxCsv csv;
		ofxCsv csvRecorder;

		vector<Subway*> subways;

		float lowX = 10000;
		float highX = -100000;
		float lowY= 10000;
		float highY = -100000;

		string subwayStation = "TEST";

		
};
