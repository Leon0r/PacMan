#include "Ghost.h"

Ghost::Ghost(PlayState* playState, Textures* texture) : GameCharacter(playState, texture)
{

}

Ghost::~Ghost()
{

}

void Ghost::update()
{
	
}

bool Ghost::handleEvent(SDL_Event& event)
{
	return true;
}