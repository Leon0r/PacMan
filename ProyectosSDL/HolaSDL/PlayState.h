#pragma once
#include "GameState.h"
#include "GameMap.h"
#include "Pacman.h"
#include "Ghost.h"

class PlayState :
	public GameState
{
public:
	PlayState(Game* game, char* level);
	~PlayState();

	void update();
	void loadGame(string level);
	// Permite hacerlo porque la declaracion del struct 'par' esta en pacmanObject.h, 
	//por lo que se puede utilizar desde cualquier sitio que incluya a PacmanObject.h 
	//o alguna clase que herede de el
	par getNextPosToroide(par pos, par dir);
};

