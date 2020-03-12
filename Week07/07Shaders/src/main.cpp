#include "ofMain.h"
#include "ofApp.h"

//========================================================================


int main( ){

#ifdef OF_TARGET_OPENGLES
	ofGLESWindowSettings settings;
	settings.glesVersion = 2;
#else
	ofGLWindowSettings settings;
	// OpenGL3 shader (which uses GLSL 1.5)
	// most graphic cards support OpneGL3, but you can run examples/gl/glinfoExample
	settings.setGLVersion(3, 2);	// define the OpenGL version we want
#endif
	ofCreateWindow(settings);


	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
