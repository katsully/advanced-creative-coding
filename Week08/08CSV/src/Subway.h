
#pragma once

#include "ofMain.h"

class Subway
{
public:
	Subway();
	Subway(string n, float x, float y);
	void display();
	bool hover(int x, int y);

	string name;
	float xCoord;
	float yCoord;

};
