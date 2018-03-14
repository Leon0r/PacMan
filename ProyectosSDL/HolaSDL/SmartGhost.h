#pragma once
#include "Ghost.h"
#include "checkML.h"

class SmartGhost :
	public Ghost
{
private:
	unsigned int age;

public:
	SmartGhost(PlayState* playState, Textures* textures);
	virtual ~SmartGhost();

	void update();
	bool handleEvent(SDL_Event& event);
	// Lee lo necesario del archivo para cargar el SmartGhost
	void loadFromFile(ifstream& level);
	// Guarda en un archivo la información del SmartGhost
	void saveToFile(ofstream& level);
};

