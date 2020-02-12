#pragma once

#include "ofMain.h"
#include "../apps/myApps/03ClassPart2/Landscape.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		vector<Landscape> pics;
		int picX;
		int picY;

		
		void mouseDragged(int x, int y, int button);
		
		
};
