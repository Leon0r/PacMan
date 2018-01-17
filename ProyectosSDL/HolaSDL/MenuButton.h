#pragma once
#include "GameObject.h"
#include "Game.h"

class MenuButton :
	public GameObject
{
	typedef void CallBackOnClick(Game* game);

protected:
	Game* game;
	CallBackOnClick* cbOnClick;

public:
	MenuButton();
	~MenuButton();

	void update() = 0;
	void render() = 0;
	bool handleEvent(SDL_Event& event);
};