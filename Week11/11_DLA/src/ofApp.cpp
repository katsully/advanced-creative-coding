#include "ofApp.h"

#define WIDTH 1024
#define HEIGHT 768

//--------------------------------------------------------------
void ofApp::setup() {

	//initialize field
	field = new bool[WIDTH * HEIGHT];

	for (int i = 0; i < WIDTH * HEIGHT; i++) {
		field[i] = false;
	}

	//setup texture
	width = WIDTH;
	height = HEIGHT;

	pixels = new unsigned char[width * height];

	texture.allocate(width, height, GL_LUMINANCE);

	for (int i = 0; i < width * height; i++) {
		pixels[i] = 255;
	}

	texture.loadData(pixels, width, height, GL_LUMINANCE);

	//seed center
	int fcenterX = width / 2;
	int fcenterY = height / 2;
	field[fcenterX + fcenterY * width] = true;

	//initialize particle array
	particleCount = 200000;
	mParticles = new Particle[particleCount];

	for (int i = 0; i < particleCount; i++) {
		Particle temp;
		temp.setup(field, WIDTH, HEIGHT);
		mParticles[i] = temp;
	}

}

//--------------------------------------------------------------
void ofApp::go() {
	for (int i = 0; i < particleCount; i++) {
		mParticles[i].update();
		if (mParticles[i].stuck) {
			pixels[mParticles[i].y * width + mParticles[i].x] = 0;
		}
	}
	texture.loadData(pixels, width, height, GL_LUMINANCE);
}

//--------------------------------------------------------------
void ofApp::draw() {
	texture.draw(0, 0);
}

void ofApp::keyPressed(int key)
{
	cout << "hello" << endl;
	go();
}
