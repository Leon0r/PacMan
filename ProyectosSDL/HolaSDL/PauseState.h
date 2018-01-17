#pragma once
#include "GameState.h"

class PauseState :
	public GameState
{
public:
	PauseState(Game* game);
	~PauseState();

	void update();
	void render();
	bool handleEvent(SDL_Event& event);
	static void resume(Game* game);
};