#pragma once

#include "ofMain.h"
#include "../apps/myApps/03class/Shape.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void ofApp::mousePressed(int x, int y, int button);
		void ofApp::mouseDragged(int x, int y, int button);
		void ofApp::keyPressed(int key);

		int x;
		int y;

		vector<Shape> shapes;
		
};
