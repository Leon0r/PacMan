#pragma once
#include <list>
#include <vector>
#include <sstream>
#include "checkML.h"
#include "GameObject.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Textures.h"

using namespace std; /// Para list

class Game;

class GameState
{
protected:
	list <GameObject*> objects;

	Game* game;

	vector <SDL_Rect> infoButton;

public:
	GameState(Game* game);
	virtual ~GameState();

	virtual void update();
	virtual void render();
	virtual void renderBackground(int text);
	virtual bool handleEvent(SDL_Event& event);
};