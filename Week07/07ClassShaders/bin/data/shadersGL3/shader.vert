#version 150


// uniform a constant - each vertex gets the same value
// modelViewProjectionMatrix is already set up for you
// the value is passed from OF
uniform mat4 modelViewProjectionMatrix;

// in as in INPUT
// position value comes from OF
// position of the pixel
in vec4 position;

// how much time has passed
// updating this value in ofApp.cpp
uniform float time;

void main(){
	float displacementHeight = 100.0f;
	float displacementY = sin(time - (position.x/100)) * displacementHeight;
	//float displacementY = sin(time) * displacementHeight;

	// this is the most basic equation needed to be passed into gl_Position
	vec4 modifiedPosition = modelViewProjectionMatrix * position;
	modifiedPosition.y += displacementY;
	gl_Position = modifiedPosition;
}