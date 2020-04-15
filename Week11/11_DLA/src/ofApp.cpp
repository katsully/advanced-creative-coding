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

	// we are using pixels on the CPU to manipulate our image
	// each image is the 'color' of the grid
	pixels = new unsigned char[width * height];

	texture.allocate(width, height, GL_LUMINANCE);

	// initialize all pixels to white
	for (int i = 0; i < width * height; i++) {
		pixels[i] = 255;
	}

	// from CPU to GPU 
	// pixels to texture
	texture.loadData(pixels, width, height, GL_LUMINANCE);

	//seed center
	// starting on center - BUT it can be changed!
	int fcenterX = width / 8;
	int fcenterY = height / 8;

	// saying that the first dot in the grid (center, center) is occupied
	// xPos + (yPos * width) - allows us to go from 2 dim xy position to 1 dim index position
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
void ofApp::update() {
	for (int i = 0; i < particleCount; i++) {
		mParticles[i].update();
		if (mParticles[i].stuck) {
			// pixel at position i becomes black
			pixels[mParticles[i].y * width + mParticles[i].x] = 0;
		}
	}
	// update our texture with our pixels!
	texture.loadData(pixels, width, height, GL_LUMINANCE);
}

//--------------------------------------------------------------
void ofApp::draw() {
	// draw our texture
	texture.draw(0, 0);
}

void ofApp::keyPressed(int key)
{
	/*cout << "hello" << endl;
	go();*/
}
