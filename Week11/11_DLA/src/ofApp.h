#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void go();
	void draw();
	void keyPressed(int key);

	ofTexture texture;
	unsigned char* pixels;
	int width, height;

	int particleCount;
	Particle* mParticles;
	bool* field;
		
};
