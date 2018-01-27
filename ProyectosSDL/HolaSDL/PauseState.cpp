#include "PauseState.h"
//#include "Game.h" // GameState.h no incluye Game.h
#include "MenuButton.h"

PauseState::PauseState(Game* game) : GameState(game)
{
	objects.push_back(new MenuButton(game->getTexture(4), 100, 300, 50, 120, resume, game));
	objects.push_back(new MenuButton(game->getTexture(3), 300, 300, 50, 120, exitGame, game));
	//objects.push_back(new MenuButton(game->getTexture(4), 100, 300, 20, 50, goToMenu, game));
}

PauseState::~PauseState()
{

}

bool PauseState::handleEvent(SDL_Event& event) 
{
	return GameState::handleEvent(event);
}

void PauseState::resume(Game* game) 
{
	game->getStateMachine()->popState();
}

void PauseState::exitGame(Game* game) {
	game->exitGame();
}

void PauseState::goToMenu(Game* game) {
	game->getStateMachine()->popState();
	game->getStateMachine()->popState();
}