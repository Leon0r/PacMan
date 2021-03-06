#include "Game.h"
#include "PlayState.h"

Game::Game()
{
	gameStateMachine = new GameStateMachine();


	if (window == nullptr || renderer == nullptr) {
		winX = winY = SDL_WINDOWPOS_CENTERED;

		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("PACMAN", winX, winY, WIN_WIDTH, WIN_HEIGTH, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}

}

Game::~Game()
{
	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		delete textures[i];
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() 
{
	load();

	while (!endGame) 
	{
		update();
		render();
		handleEvents();
	}
	
}

void Game::update()
{
	gameStateMachine->currentState()->update();
}

void Game::render()
{
	clearScreen(); // Para limpiar la pantalla despues de cada frame
	gameStateMachine->currentState()->render();
	SDL_RenderPresent(renderer);
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

	gameStateMachine->pushState(new MainMenuState(this));

}

void Game::loadNewPlayState() {
	gameStateMachine->pushState(new PlayState(this, 1));
}

void Game::loadSavedPlayState() {
	try {
		gameStateMachine->pushState(new PlayState(this));
	}
	catch (FileNotFoundError e) {
		cout << e.what() << endl;
		cout << "Iniciando nueva partida";
		gameStateMachine->pushState(new PlayState(this,1));
	}
}

void Game::loadPauseState() {
	gameStateMachine->pushState(new PauseState(this));
}

void Game::loadEndState() {
	gameStateMachine->pushState(new EndState(this));
}

void Game::loadMainMenuState()
{
	while (getStateMachine()->getSize() > 0 && dynamic_cast<MainMenuState*>(getStateMachine()->currentState()) == nullptr)
		getStateMachine()->popState();
}

void Game::exitGame() {
	endGame = true;
	while (getStateMachine()->getSize() > 0)
		getStateMachine()->popState();
}