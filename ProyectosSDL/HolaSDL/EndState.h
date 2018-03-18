#pragma once
#include "checkML.h"
#include "GameState.h"

class EndState :
	public GameState
{
public:
	EndState(Game* game);
	virtual ~EndState(){}

	virtual void render();

	static void loadMenuState(Game* game);
	static void exitGame(Game* game);
};