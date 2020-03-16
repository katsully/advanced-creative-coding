#version 150

// SECOND
uniform vec4 globalColor;

// out for OUTput - this gets passed to the framebuffer
// vec4 - RGBA
out vec4 outputColor;

uniform float windowWidth;
uniform float windowHeight;

void main()
{
    
	float r = gl_FragCoord.x / windowWidth;
	float g = gl_FragCoord.y / windowHeight;
	float b = 1.0;
	float a = 1.0;
	outputColor = vec4(r, g, b, a);

}