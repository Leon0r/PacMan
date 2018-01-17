#pragma once
#include "Ghost.h"

class SmartGhost :
	public Ghost
{
private:
	unsigned int age;

public:
	SmartGhost(PlayState* playState);
	~SmartGhost();

	void update();
	void render();
	bool handleEvent(SDL_Event& event);
	// Lee lo necesario del archivo para cargar el SmartGhost
	void loadFromFile(ifstream& level);
	// Guarda en un archivo la información del SmartGhost
	void saveToFile(ofstream& level);
};

