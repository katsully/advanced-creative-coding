#include "Face.h"

Face::Face()
{

}

Face::Face(ofTexture tex, int x, int y, ofColor t)
{
	texture = tex;
	xPos = x;
	yPos = y;

	tint = t;
}

void Face::display()
{
	// ofSetColor(ofColor::red);
	ofSetColor(tint);
	texture.draw(xPos, yPos);
}

