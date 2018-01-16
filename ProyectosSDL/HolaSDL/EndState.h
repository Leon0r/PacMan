#pragma once
#include "GameState.h"

class EndState :
	public GameState
{
public:
	EndState(Game* game);
	~EndState();

	void update();
	void render();
	bool handleEvent(SDL_Event& e);
};