#include "Pacman.h"
#include "PlayState.h" 

Pacman::Pacman(PlayState* playState, Textures* texture) : GameCharacter(playState, texture)
{

}

Pacman::~Pacman()
{

}

void Pacman::update() 
{

}

bool Pacman::handleEvent(SDL_Event& event) 
{
	return true;
}

// Lee lo necesario del archivo para cargar el Pacman
void Pacman::loadFromFile(ifstream& level)
{
	GameCharacter::loadFromFile(level);
	if (!level.eof()) // Si es un archivo de guardado lee también la energía y las vidas
		level >> energy >> lifes;
}

// Guarda en un archivo la información del Pacman
void Pacman::saveToFile(ofstream& level)
{
	GameCharacter::saveToFile(level);
	level << " " << energy << " " << lifes;
}