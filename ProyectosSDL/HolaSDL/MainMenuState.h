#pragma once
#include "GameState.h"

class MainMenuState :
	public GameState
{
public:
	MainMenuState();
	~MainMenuState();

	void update();
	void render();
	bool handleEvent(SDL_Event& e);
};