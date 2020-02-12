#pragma once

#include "ofMain.h"
#include "../apps/myApps/02shapeGenerator/Shape.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		Shape myFirstShape;
		Shape definedShape;

		// A c++ vector is a type of container (like an array) that allows the storage of multiple elements (numbers, strings, objects etc.) in a format that can grow or shrink dynamically
		vector<Shape> shapes;  // create an empty vector of Shapes    

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
