#include "Subway.h"

Subway::Subway()
{

}

Subway::Subway(string n, float x, float y)
{
	name = n;
	xCoord = x;
	yCoord = y;
}

void Subway::display()
{
	ofSetColor(255, 0, 0);
	ofDrawRectangle(xCoord, yCoord, 10, 10);
}

bool Subway::hover(int x, int y)
{
	if (xCoord <= x && x <= (xCoord + 10)){
		if (yCoord <= y && y <= (yCoord + 10)) {
			return true;
		}
	}
	return false;
}