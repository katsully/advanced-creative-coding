#include "Face.h"

Face::Face()
{

}

Face::Face(ofTexture tex, int x, int y)
{
	texture = tex;
	xPos = x;
	yPos = y;
}

void Face::display()
{
	texture.draw(xPos, yPos);
}

