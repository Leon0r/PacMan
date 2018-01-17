#include "SmartGhost.h"



SmartGhost::SmartGhost(PlayState* playState) : Ghost(playState)
{
}


SmartGhost::~SmartGhost()
{
}

void SmartGhost::update() 
{

}

void SmartGhost::render()
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