#pragma once

#include "ofMain.h"
#include "FracCircle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void drawFractalCircle(float x, float y, float radius);

		vector<FracCircle*> circles;
		float startAngle = 0;
		float angleVar = 0.1;
		ofColor color;
		float hue = 0;
		
};
