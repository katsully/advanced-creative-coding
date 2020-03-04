#include "KochLine.h"

KochLine::KochLine() {

}

KochLine::KochLine(ofVec2f a, ofVec2f b) {
	start = a;
	end = b;
}

void KochLine::display() {
	ofDrawLine(start, end);
}

ofVec2f KochLine::getPointA()
{
	return start;
}

ofVec2f KochLine::getPointB()
{
	// get length of the line
	ofVec2f temp = end - start;
	// divide by 3
	temp /= 3;
	// offset of the starting point (pushes it halfway down)
	temp += start;

	return temp;
}

ofVec2f KochLine::getPointC()
{
	// start at the beginning
	ofVec2f tempStart = start;
	ofVec2f length = end - start;

	// move 1/3 way to point B
	length /= 3;
	// tempStart is at point B
	tempStart += length;

	// rotate "above" the line 60 deg
	// length is now point C minus the offset of our starting position
	length.rotate(-60);
	// add offset of starting position
	tempStart += length;

	return tempStart;
}

ofVec2f KochLine::getPointD()
{
	ofVec2f temp = end - start;
	temp *= (2.0f / 3.0f);
	temp += start;
	return temp;
}
ofVec2f KochLine::getPointE()
{
	return end;
}
