#pragma once
#include <list>
#include "Game.h"
#include "GameObject.h"
#include "SDL.h"
#include "SDL_image.h"

using namespace std; /// Para list

class GameState
{
protected:
	list <GameObject*> objects;
	Game* game;

public:
	GameState();
	virtual ~GameState();

	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& e);
};