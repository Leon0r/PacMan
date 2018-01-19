#pragma once
#include "GameObject.h"
#include "Game.h"

typedef void CallBackOnClick(Game* game);

class MenuButton :
	public GameObject
{
protected:
	Game * game;
	CallBackOnClick* cbOnClick;

public:
	MenuButton(Textures* texture, int x, int y, int h, int w, CallBackOnClick* cbOnClick);
	~MenuButton();

	void update();
	void render();
	bool handleEvent(SDL_Event& event);

	void setCallBack(CallBackOnClick* cbOnClick) { this->cbOnClick = cbOnClick; }
};