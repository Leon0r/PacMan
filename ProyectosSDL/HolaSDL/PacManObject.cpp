#include "PacManObject.h"
#include "PlayState.h" 

PacManObject::PacManObject(PlayState* playState, Textures* texture):GameObject(texture)
{
	this->playState = playState;
	destRect.h = cellSize;
	destRect.w = cellSize;
}

PacManObject::~PacManObject()
{

}