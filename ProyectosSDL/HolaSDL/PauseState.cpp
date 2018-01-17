#include "PauseState.h"
#include "Game.h" // GameState.h no incluye Game.h

PauseState::PauseState(Game* game) : GameState(game)
{
}

PauseState::~PauseState()
{

}

void PauseState::update() 
{

}

void PauseState::render() 
{

}

bool PauseState::handleEvent(SDL_Event& event) 
{
	return true;
}

void PauseState::resume(Game* game) 
{
	game->getStateMachine()->popState();
}