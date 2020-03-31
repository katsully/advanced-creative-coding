#include "Trail.h"

Trail::Trail()
{

}

Trail::Trail(float x, float y, ofColor c, float r)
{
	position = ofVec2f(x,y);
	color = c;
	radius = r;
}

bool Trail::update()
{
	--transparency;
	radius -= .1;

	return transparency > 0 && radius > 0.0f;
}

void Trail::display()
{
	ofSetColor(color, transparency);
	ofDrawCircle(position, radius);
}
