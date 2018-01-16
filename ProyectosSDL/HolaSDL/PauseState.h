#pragma once
#include "GameState.h"

class PauseState :
	public GameState
{
public:
	PauseState();
	~PauseState();

	void update();
	void render();
	bool handleEvent(SDL_Event& e);
};