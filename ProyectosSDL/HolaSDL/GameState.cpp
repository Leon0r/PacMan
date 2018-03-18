#include "GameState.h"
#include "Game.h"

GameState::GameState(Game* game)
{
	this->game = game;
}

GameState::~GameState()
{
	for (GameObject* o : objects)
		delete o;
}

void GameState::update() 
{
	for (GameObject* o : objects)
		o->update();
}

void GameState::render() 
{
	for (GameObject* o : objects)
		o->render();
}

void GameState::renderBackground()
{
	SDL_Rect fondo;
	fondo.x = 0; fondo.y = 0;
	fondo.w = WIN_WIDTH; fondo.h = WIN_HEIGTH;
	game->getTexture(0)->renderFullText(fondo);
}


bool GameState::handleEvent(SDL_Event& event) 
{
	bool handled = false; // Comprueba si el evento ya ha sido recogido por algún botón
	auto it = objects.begin();
	while (it != objects.end() && !handled)
		if ((*it)->handleEvent(event))
			handled = true;
		else 
			++it;

	return handled; // Devuelve true si algun objeto lo ha manejado y false si no
}