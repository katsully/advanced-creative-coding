#include "Particle.h"


float mag(ofVec2f in) {
	float retf = sqrt(in.x * in.x + in.y * in.y);
	return retf;
}

Particle::Particle(ofVec2f l) {
	counter = 0;
	float randmin = -HALF_PI;
	float randmax = 0;

	float r = ofRandom(0, TWO_PI);
	float x = cos(r);
	float y = sin(r);
	acc = ofVec2f(x / 250, y / 250);

	float q = ofRandom(0, 1);
	r = ofRandom(randmin, randmax);
	x = cos(r) * q;
	y = sin(r) * q;
	vel = ofVec2f(x, y);
	loc = l;
	hist = new ofVec2f[1000];
}

void Particle::update() {
	// currVelocity = previousVelocity + currentAccerlation
	vel += acc;
	// location = previousLocation + currVelocity
	loc += vel;

	// adding to the trail
	// ofGetFrameNum() % 10 == 0 ---> every 10 frames add to the trail
	if (ofGetFrameNum() % 10 == 0 && counter < 1000) {
		hist[counter].x = loc.x;
		hist[counter].y = loc.y;
		counter++;
	}
}

void Particle::draw() {
	ofFill();
	ofSetColor(100, 100, 100, 100);
	// drawArrowHead(vel, loc, 10);
	ofNoFill();
	ofSetColor(0, 0, 0, 100);

	//for (int i = 0; i < counter-1; i++) {
	//	ofDrawLine(hist[i].x, hist[i].y, hist[i + 1].x, hist[i + 1].y);
	//	//ofDrawCircle(hist[i].x, hist[i].y, 3);
	//}
	//ofDrawCircle(loc.x, loc.y, 3);

	ofBeginShape();
	for (int i = 0; i < counter; i++) {
		ofVertex(hist[i].x, hist[i].y);
	}
	if (counter > 0) ofVertex(loc.x, loc.y);
	// true 'closes' the shape, false 'keeps it open'
	ofEndShape(false);
}

void Particle::drawArrowHead(ofVec2f v, ofVec2f loc, float scale) {
	ofPushMatrix();
	float arrowsize = 5.0f;
	ofTranslate(loc.x, loc.y, 0);
	float rotate = atan2(v.y, v.x);
	ofRotate(ofRadToDeg(rotate), 0, 0, 1);

	float len = mag(v) * scale;
	arrowsize = ofMap(len, 0.f, 10.f, 0.f, 1.f, false) * arrowsize;

	ofLine(0, 0, len - arrowsize, 0);

	ofBeginShape();
	ofVertex(len, 0);
	ofVertex(len - arrowsize, arrowsize / 2);
	ofVertex(len - arrowsize, -arrowsize / 2);
	ofEndShape(true);

	ofPopMatrix();
}