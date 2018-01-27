#pragma once
#include "GameState.h"

class PauseState :
	public GameState
{
public:
	PauseState(Game* game);
	~PauseState();

	bool handleEvent(SDL_Event& event);
	static void resume(Game* game);
	static void exitGame(Game* game);
	static void goToMenu(Game* game);
};