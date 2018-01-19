#pragma once
#include "GameState.h"

class MainMenuState :
	public GameState
{
public:
	MainMenuState(Game* game);
	~MainMenuState();

	void update();
	void render();
	bool handleEvent(SDL_Event& event);

	static void loadNewGame(Game* game);
	static void loadSavedGame(Game* game);
	static void exitGame(Game* game);

};