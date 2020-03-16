#version 150

// a uniform is a constant - ea vertex the same value
// modelViewProjectionMatrix is already set up for you
// a value passed in from OF
uniform mat4 modelViewProjectionMatrix;


// different for every vertex (what's being INputted)
// position value comes from OF
in vec4 position;

void main(){

	gl_Position = modelViewProjectionMatrix * position;
}
