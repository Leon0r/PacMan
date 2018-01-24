#include "MenuButton.h"

MenuButton::MenuButton(Textures* texture, int x, int y, int h, int w, CallBackOnClick* cbOnClick, Game* game) :GameObject(texture)
{
	GameObject::texture = texture;
	destRect.x = x;
	destRect.y = y;
	destRect.h = h;
	destRect.w = w;
	this->game = game;
	//this->cbOnClick(this->game) = cbOnClick(game);
	setCallBack(cbOnClick);
}

MenuButton::~MenuButton()
{
}

void MenuButton::update()
{

}

void MenuButton::render()
{
	texture->renderFullText(destRect);
}

bool MenuButton::handleEvent(SDL_Event& event)
{
	bool handled = false;
	if(event.type == SDL_MOUSEBUTTONDOWN)
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			SDL_Point p;
			SDL_GetMouseState(&p.x, &p.y);

			if (SDL_PointInRect(&p, &destRect)) 
			{
				handled = true;
				cbOnClick(game); // Con esto se consigue un botón genérico
			}
		}
	return handled;
}

