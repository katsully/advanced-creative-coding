#version 150

// out like OUTput - this is what gets passed to the framebuffer
// vec4 - R,G,B,A
out vec4 outputColor;

// this value will come of ofApp.cpp
uniform vec4 globalColor;

void main(){
	outputColor = globalColor;
}