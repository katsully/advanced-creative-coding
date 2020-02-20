#include "TestImg.h"



TestImg::TestImg()
{
	x = ofRandom(500);
	y = ofRandom(500);
}


TestImg::~TestImg()
{
}

// void TestImg::draw(ofImage img) {
void TestImg::draw(ofImage* img) {
	//img.draw(x, y);
	img->draw(x, y); // img is now a pointer

}
