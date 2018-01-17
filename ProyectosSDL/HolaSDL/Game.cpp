#include "Game.h"

Game::Game()
{
	gameStateMachine = new GameStateMachine();
	gameStateMachine->pushState(new MainMenuState(this));

}

Game::~Game()
{

}

void Game::run() 
{
	while (!endGame) 
	{
		handleEvents();
		update();
		render();
	}
	
}

void Game::update()
{
	gameStateMachine->currentState()->update();
}

void Game::render()
{
	gameStateMachine->currentState()->render();
	
}

void Game::handleEvents() 
{
	while (SDL_PollEvent(&event) && !endGame)
	{
		if (event.type == SDL_QUIT) endGame = true;
		else
			gameStateMachine->currentState()->handleEvent(event);
	}
}