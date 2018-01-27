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
};

