#pragma once
#include "checkML.h"
#include "GameState.h"

class MainMenuState :
	public GameState
{
public:
	MainMenuState(Game* game);
	virtual ~MainMenuState() {}
	
	virtual void render();

	static void loadNewGame(Game* game);
	static void loadSavedGame(Game* game);
	static void exitGame(Game* game);

};