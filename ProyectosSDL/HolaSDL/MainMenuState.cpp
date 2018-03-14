#include "MainMenuState.h"
#include "MenuButton.h"

MainMenuState::MainMenuState(Game* game) : GameState(game)
{
	objects.push_back(new MenuButton(game->getTexture(1), 400, 500, 50, 120, loadSavedGame, game));
	objects.push_back(new MenuButton(game->getTexture(2), 100, 100, 50, 120, loadNewGame, game));
	objects.push_back(new MenuButton(game->getTexture(3), 250, 250, 50, 120, exitGame, game));
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