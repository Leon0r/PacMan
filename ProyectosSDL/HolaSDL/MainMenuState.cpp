#include "MainMenuState.h"
#include "MenuButton.h"

MainMenuState::MainMenuState(Game* game) : GameState(game)
{
	renderBackground(0);
	objects.push_back(new MenuButton(game->getTexture(1), 340, 300, 50, 120, loadSavedGame, game));
	objects.push_back(new MenuButton(game->getTexture(2), 150, 300, 50, 120, loadNewGame, game));
	objects.push_back(new MenuButton(game->getTexture(3), 250, 400, 50, 120, exitGame, game));
}

void MainMenuState::render()
{
	renderBackground(0);
	GameState::render();
}

void MainMenuState::loadNewGame(Game* game) {
	game->loadNewPlayState();
}

void MainMenuState::loadSavedGame(Game* game) {
	game->loadSavedPlayState();
}

void MainMenuState::exitGame(Game* game) {
	game->exitGame();
}