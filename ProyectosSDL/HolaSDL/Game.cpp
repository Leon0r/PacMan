#include "Game.h"

Game::Game()
{
	gameStateMachine = new GameStateMachine();
	gameStateMachine->pushState(new MainMenuState(this));

	if (window == nullptr || renderer == nullptr) {
		winX = winY = SDL_WINDOWPOS_CENTERED;

		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("PACMAN", winX, winY, winWidth, winHeigth, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}

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

void Game::load() {
	for (int i = 0; i < NUM_TEXTURES; i++) {
		textures[i] = new Textures;
		textures[i]->loadTextureFromImage(renderer, infoT[i].filename, infoT[i].numFils, infoT[i].numCols);
	}


}

void Game::loadNewPlayState() {
	gameStateMachine->pushState(new PlayState(this));
}

void Game::loadSavedPlayState() {
	int level;
	try {
		cin >> level;
	}
	catch (FileNotFoundError e){
		cout << e.what();
	}

	gameStateMachine->pushState(new PlayState(this));
}