#include "Trail.h"

Trail::Trail()
{


}

Trail::Trail(float x, float y, ofColor c, int r)
{
	position = ofVec2f(x, y);
	color = c;
	radius = r;
}

// fade out our trail
bool Trail::update()
{
	--transparency;
	radius -= .1;

	if (transparency > 0 && radius > 0) {
		return true;
	}

	return false;
}

void Trail::display()
{
	ofSetColor(color, transparency);
	// uniform trail radius
	// ofDrawCircle(position, 3);

	// dynamic trail radius
	ofDrawCircle(position, radius);
}