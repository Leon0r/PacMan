#include "MainMenuState.h"
#include "MenuButton.h"

MainMenuState::MainMenuState(Game* game) : GameState(game)
{
	objects.push_back(new MenuButton(game->getTexture(1), 100, 100, 20, 50, loadNewGame, game));
	objects.push_back(new MenuButton(game->getTexture(2), 500, 500, 20, 50, loadSavedGame, game));
	objects.push_back(new MenuButton(game->getTexture(2), 250, 250, 20, 50, exitGame, game));
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::update() {
	GameState::update();
}

void MainMenuState::render() {
	GameState::render();
}

bool MainMenuState::handleEvent(SDL_Event& event) {
	return GameState::handleEvent(event);
}

void MainMenuState::loadNewGame(Game* game) {
	cout << "coso";
	game->loadNewPlayState();
}

void MainMenuState::loadSavedGame(Game* game) {
	game->loadSavedPlayState();
}

void MainMenuState::exitGame(Game* game) {
	game->exitGame();
}