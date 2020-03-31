#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

#include "Trail.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxCsv csv;
		int row;
		unsigned int numCols;

		float xMin = 10000;
		float xMax = -10000;
		float yMin = 100000;
		float yMax = -10000;

		vector<ofVec2f> positions;
		vector<ofVec2f> velocities;
		vector<ofVec2f> accelerations;
		bool start = true;

		std::vector<Trail*> trails;

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
		
};
