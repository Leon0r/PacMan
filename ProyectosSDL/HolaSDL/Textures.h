#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

// Para detectar basura
#include "checkML.h"

using namespace std;

class Textures
{
private:
	SDL_Texture* texture = nullptr;
	SDL_Renderer* textRender = nullptr; // puntero al renderer del game
	SDL_Rect originRect;

	int w = 0; // Texture width (px)
	int h = 0; // Texture heigth (px)

	unsigned int fw = 0; // Frame width (px)
	unsigned int fh = 0; // Frame heigth (px)

	unsigned int numRows; // N�mero de filas de los frames de la textura
	unsigned int numCols; // N�mero de columnas de los frames de la textura

public:
	Textures();

	// Destruye la textura y pone el puntero a null
	~Textures();

	// Carga textura de una imagen
	bool Textures::loadTextureFromImage(SDL_Renderer* renderer, const char* filename, int numFils = 1, int numColumns = 1);

	// Renderiza la textura entera en la posici�n y tama�o definidas por rectDest
	void Textures::renderFullText(const SDL_Rect& rectDest, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Renderiza el frame (row, col) en la posici�n y tama�o definida por destRect
	void Textures::renderFrame(const SDL_Rect& destRect, unsigned int row, unsigned int col, SDL_RendererFlip flip = SDL_FLIP_NONE);
};