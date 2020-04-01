#include "Particle.h"

Particle::Particle()
{

}

Particle::Particle(ofVec2f pos, ofVec2f vel, ofVec2f acc)
{
	position = pos;
	velocity = vel;
	acceleration = acc;
}

void Particle::update()
{
	position += velocity;
	velocity += acceleration;
}

void Particle::display()
{
	ofDrawCircle(position, 7);
}

