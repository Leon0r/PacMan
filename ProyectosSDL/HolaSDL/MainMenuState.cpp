#include "MainMenuState.h"
#include "MenuButton.h"

MainMenuState::MainMenuState(Game* game) : GameState(game)
{
	new MenuButton(game->getTexture(1), 0, 0, 20, 50, loadNewGame);
	new MenuButton(game->getTexture(2), 0, 0, 20, 50, loadSavedGame);
	new MenuButton(game->getTexture(2), 0, 0, 20, 50, exitGame);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::update() {

}

void MainMenuState::render() {

}

bool MainMenuState::handleEvent(SDL_Event& event) {
	return GameState::handleEvent(event);
}

void MainMenuState::loadNewGame(Game* game) {
	game->loadNewPlayState();
}

void MainMenuState::loadSavedGame(Game* game) {
	game->loadSavedPlayState();
}

void MainMenuState::exitGame(Game* game) {
	game->getStateMachine()->popState();
}