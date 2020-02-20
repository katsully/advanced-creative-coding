#pragma once

#include "ofMain.h"
#include "../apps/myApps/03PassByValueRef/TestImg.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofImage image;
		vector<TestImg*> smiles;
		//  
		// Important: when you create a class  
		//  and then a vector to put the class   
		//  instances into, always use pointers  
		//  to the class, otherwise you get very   
		//  strange results and memory leaks.   
		//  So don't do:  
		//   vector<TestImg> ants; 

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
