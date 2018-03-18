#include "EndState.h"
#include "MenuButton.h"

EndState::EndState(Game* game) : GameState(game)
{
	objects.push_back(new MenuButton(game->getTexture(1), 400, 500, 50, 120, loadMenuState, game));
	objects.push_back(new MenuButton(game->getTexture(3), 250, 250, 50, 120, exitGame, game));
}

void EndState::render()
{
	renderBackground();
	GameState::render();
}

void EndState::loadMenuState(Game* game)
{
	game->loadMainMenuState();
}

void EndState::exitGame(Game* game)
{
	game->exitGame();
}