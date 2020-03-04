#pragma once

#include "ofMain.h"
#include "KochLine.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		vector<KochLine*> lines;
		// generate our lines
		void generate();
		
};
