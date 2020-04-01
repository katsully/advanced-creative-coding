
#include "ofMain.h"

#pragma once


class Particle
{
public:
	Particle();
	Particle(ofVec2f pos, ofVec2f vel, ofVec2f acc);
	void update();
	void display();
	
	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;

};

