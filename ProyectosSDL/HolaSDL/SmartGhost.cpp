#include "SmartGhost.h"
#include "PlayState.h" 

SmartGhost::SmartGhost(PlayState* playState, Textures* texture) : Ghost(playState, texture)
{
	frameOrigX_ = 8;
	frame.x = frameOrigX_;
}

SmartGhost::~SmartGhost()
{
}

void SmartGhost::update() 
{
	selectDir();
	GameCharacter::update();
}

bool SmartGhost::handleEvent(SDL_Event& event)
{
	return true;
}

void SmartGhost::selectDir()
{
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
	level << "1 ";
	GameCharacter::saveToFile(level);
	level << " " << age;
}