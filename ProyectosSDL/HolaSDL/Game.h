#pragma once
#include <iostream>
#include <string>
#include "checkML.h"
#include "FileNotFoundError.h"
#include "GameStateMachine.h"
#include "Textures.h"


using namespace std;

const int NUM_TEXTURES = 7;
const int WIN_WIDTH = 600;
const int WIN_HEIGTH = 600;

// Struct con lo necesario para inicializar las texturas
struct infoText {
	const char* filename;
	int numFils;
	int numCols;
};

class Game
{
private:

	bool endGame = false; // Booleano de control de fin de juego
	GameStateMachine* gameStateMachine;
	SDL_Event event;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Textures* textures[NUM_TEXTURES]; // Array de texturas

									  // Tamaño y posición de la ventana
	int winX,
		winY;

	// Array con la información de las texturas
	infoText infoT[NUM_TEXTURES]{
		{ "..\\images\\Background.png", 1, 1 },
		{ "..\\images\\LoadGame.png", 1, 1 },
		{ "..\\images\\NewGame.png", 1, 1 },
		{ "..\\images\\ExitGame.png", 1, 1 },
		{ "..\\images\\ResumeGame.png", 1, 1 },
		{ "..\\sprites\\pacmanCellsFull.png", 4, 1 },
		{ "..\\sprites\\pacmanSheet.png", 4, 14 }
	};

public:

	Game();
	~Game();

	void run();
	void update();
	void render();
	void handleEvents();

	void load();
	GameStateMachine* getStateMachine() { return gameStateMachine; };

	Textures* getTexture(int pos) { return (textures[pos]); };
	void clearScreen() { SDL_RenderClear(renderer); } // Para limpiar la pantalla

	void loadNewPlayState();
	void loadSavedPlayState();
	void loadPauseState();
	void exitGame();
};