#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

uniform float mouseRange;
uniform vec2 mousePos;
uniform vec4 mouseColor;

void main(){
	// copy position so we can work with it
	vec4 pos = position;

	// direction vector from mouse position to vertex position
	vec2 dir = pos.xy - mousePos;

	// dist between the mouse position and vertex position
	float dist = distance(pos.xy, mousePos);

	// check vertex is within mouse range
	if(dist > 0.0 && dist < mouseRange) {
		// normalise distance between 0 and 1
		float distNorm = dist / mouseRange;

		// flip it so the closer we are the greater the repulision
		distNorm = 1.0 - distNorm;

		// make the direction vector magnitude fade out the further it gets from 
		// mouse position
		dir *= distNorm;

		// add the direction vector to the vertex position
		pos.x += dir.x;
		pos.y += dir.y;

	}

	// gl_Position is modified by the location of the mouse RELATIVE to its own position
	gl_Position = modelViewProjectionMatrix * pos;
}
