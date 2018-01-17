#pragma once
#include "PacManObject.h"

struct par
{
	int x;
	int y;
};

class GameCharacter :
	public PacManObject
{
protected:
	par posIni,
		posAct,
		dir;

	par frame; /// Para las animaciones

public:
	GameCharacter(PlayState* playState);
	virtual ~GameCharacter();

	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& event);
	// Lee lo necesario del archivo para cargar el GameCharacter
	virtual void loadFromFile(ifstream& level);
	// Escribe posAct, posIni, dir del GameCharacter
	virtual void saveToFile(ofstream& level);
};

