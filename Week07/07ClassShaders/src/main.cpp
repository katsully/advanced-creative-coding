#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	

	ofGLWindowSettings settings;
	// we're using -> OpenGL3.2 shader (uses GLSL 1.5)
	// if you're using OpenGL2 (using GLSL 1.2)
	settings.setGLVersion(3, 2);

	ofCreateWindow(settings);
	
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
