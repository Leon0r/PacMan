#pragma once
#include "SDL.h"
#include "SDL_image.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& e);
};