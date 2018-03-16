#pragma once
#include "Ghost.h"
#include "checkML.h"

const int ADUL_AGE = 40;
const int DEATH_AGE = 200;
const int TIME_SALIDA = 30;

class SmartGhost :
	public Ghost
{
protected:
	unsigned int age;
	int timeExit = TIME_SALIDA;
	bool dead = false;
	par targetPos;

	virtual void selectDir();
	virtual void dieOld();

public:
	SmartGhost(PlayState* playState, Textures* textures);
	virtual ~SmartGhost();

	void update();
	bool handleEvent(SDL_Event& event);

	bool isDead() { return dead; }
	virtual void death() { timeExit = TIME_SALIDA; GameCharacter::death(); }
	// Lee lo necesario del archivo para cargar el SmartGhost
	void loadFromFile(ifstream& level);
	// Guarda en un archivo la información del SmartGhost
	void saveToFile(ofstream& level);
};

