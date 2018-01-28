#pragma once
#include "checkML.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Textures.h"

class GameObject
{
protected:
	Textures* texture;
	SDL_Rect destRect;

public:
	GameObject() {}
	GameObject(Textures* texture);
	virtual ~GameObject();

	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool handleEvent(SDL_Event& event) = 0;
};