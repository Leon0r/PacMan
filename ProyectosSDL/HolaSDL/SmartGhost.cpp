#include "SmartGhost.h"
#include "PlayState.h" 


SmartGhost::SmartGhost(PlayState* playState, Textures* texture) : Ghost(playState, texture)
{
	frame.x = 8;
}


SmartGhost::~SmartGhost()
{
}

void SmartGhost::update() 
{

}

bool SmartGhost::handleEvent(SDL_Event& event)
{
	return true;
}

// Lee lo necesario del archivo para cargar el SmartGhost
void SmartGhost::loadFromFile(ifstream& level)
{
	GameCharacter::loadFromFile(level);
	level >> age;
}

// Guarda en un archivo la información del Pacman
void SmartGhost::saveToFile(ofstream& level)
{
	GameCharacter::saveToFile(level);
	level << " " << age;
}