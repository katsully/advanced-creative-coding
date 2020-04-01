#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "Trail.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		ofxCsv csv;

		float xMin;
		float xMax;
		float yMin;
		float yMax;

		int row = 7;

		vector<ofVec2f> positions;
		vector<ofVec2f> velocities;
		vector<ofVec2f> accelerations;

		vector<Trail*> trails;

		vector<Particle*> particles;

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
