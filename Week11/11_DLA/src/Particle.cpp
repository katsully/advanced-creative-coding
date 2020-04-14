#include "Particle.h"

//--------------------------------------------------------------
void Particle::setup(bool* _field, int _w, int _h) {
	field = _field;
	w = _w;
	h = _h;
	stuck = false;
	reset();
}

//--------------------------------------------------------------
void Particle::reset() {
	do {
		x = ofRandom(0, ofGetWidth());
		y = ofRandom(0, ofGetHeight());
	} while (field[y * ofGetWidth() + x]);
}

//--------------------------------------------------------------
void Particle::update() {
	if (!stuck) {

		x += round(ofRandomf());
		y += round(ofRandomf());

		if (x < 0 || y < 0 || x > w || y > h) {
			this->reset();
			return;
		}

		if (!alone()) {
			stuck = true;
			field[y * w + x] = true;
		}
	}
}

//--------------------------------------------------------------
int Particle::round(float _in) {
	if (_in > 0.0f)
		return ceil(_in);
	else if (_in < 0.0f)
		return floor(_in);
	else
		return 0;
}

//--------------------------------------------------------------
bool Particle::alone() {
	int cx = x;
	int cy = y;

	int lx = cx - 1;
	int rx = cx + 1;
	int ty = cy - 1;
	int by = cy + 1;

	if (cx <= 0 || cx >= w || lx <= 0 || lx >= w || rx <= 0 || rx >= w ||
		cy <= 0 || cy >= h || ty <= 0 || ty >= h || by <= 0 || by >= h) {
		return true;
	}

	cy *= w;
	by *= w;
	ty *= w;

	if (field[cx + ty] || field[lx + cy] || field[rx + cy] || field[cx + by]) {
		return false;
	}

	if (field[lx + ty] || field[lx + by] || field[rx + ty] || field[rx + by]) {
		return false;
	}

	return true;
}
