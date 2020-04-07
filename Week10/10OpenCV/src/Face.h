#pragma once
#include "ofMain.h"

class Face
{
public:
	Face();
	Face(ofTexture tex, int x, int y, ofColor t);
	void display();

	ofTexture texture;
	int xPos;
	int yPos;

	ofColor tint;
};

