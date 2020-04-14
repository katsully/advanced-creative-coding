#include "ofMain.h"

class Particle {
public:
	ofVec2f loc, vel, acc;
	ofVec2f* hist;
	int counter;
	Particle() {};
	Particle(ofVec2f l);
	void update();
	void draw();
	void drawArrowHead(ofVec2f v, ofVec2f loc, float scale);
};
