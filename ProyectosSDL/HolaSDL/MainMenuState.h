#pragma once
#include "GameState.h"

class MainMenuState :
	public GameState
{
public:
	MainMenuState(Game* game, vector <Textures*> t);
	~MainMenuState();

	void update();
	void render();
	bool handleEvent(SDL_Event& event);

	static void cargaNuevaPartida();
};