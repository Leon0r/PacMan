#include "MenuButton.h"

MenuButton::MenuButton()
{
}

MenuButton::~MenuButton()
{
}

void MenuButton::update()
{

}

void MenuButton::render()
{
	
}

bool MenuButton::handleEvent(SDL_Event& event)
{
	bool handled = false;
	if(event.type == SDL_MOUSEBUTTONDOWN)
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			SDL_Point p;
			if (SDL_PointInRect(&p, &destRect)) 
			{
				handled = true;
				cbOnClick(game); // Con esto se consigue un botón genérico
			}
		}
	return handled;
}