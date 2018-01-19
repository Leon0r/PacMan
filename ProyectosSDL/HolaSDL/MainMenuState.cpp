#include "MainMenuState.h"
#include "MenuButton.h"

MainMenuState::MainMenuState(Game* game, vector <Textures*> t) : GameState(game)
{
	for (int i = 0; i < t.size(); i++) {
		objects.push_back(new MenuButton(t[i], infoButton[i].x, infoButton[i].y, infoButton[i].h, infoButton[i].w, nullptr));
	}

	auto it = objects.begin();
	(*it)->render();
	++it;
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

void MainMenuState::cargaNuevaPartida() {

}