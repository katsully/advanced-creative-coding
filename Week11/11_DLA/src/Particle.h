#include "ofMain.h"

#pragma once
class Particle
{
public:

	void setup(bool* _field, int _w, int _h);
	void reset();
	void update();
	bool alone();

	int round(float _in);

	int x, y, w, h;
	bool stuck;
	bool* field;
};

