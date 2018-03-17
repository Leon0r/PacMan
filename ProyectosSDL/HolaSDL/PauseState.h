#pragma once
#include "checkML.h"
#include "GameState.h"

class PauseState :
	public GameState
{
public:
	PauseState(Game* game);
	virtual ~PauseState() {}

	virtual void render();

	bool handleEvent(SDL_Event& event);
	static void resume(Game* game);
	static void exitGame(Game* game);
	static void loadMenuState(Game* game);
};