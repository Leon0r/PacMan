#include "GameState.h"

GameState::GameState()
{
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

void GameState::handleEvent(SDL_Event& e) 
{
	bool handled = false; // Comprueba si el evento ya ha sido recogido por algún botón
	auto it = objects.begin();
	while (it != objects.end() && !handled)
		if ((*it)->handleEvent(e))
			handled = true;
		else ++it;
}