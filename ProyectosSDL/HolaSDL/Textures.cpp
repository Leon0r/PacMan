#include "Textures.h"

Textures::Textures()
{
}

// Destruye la textura y pone el puntero a null
Textures::~Textures() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
	w = h = fw = fh = numCols = numRows = 0; 
}

// Carga textura de una imagen
bool Textures::loadTextureFromImage(SDL_Renderer* renderer, const char* filename, int numFils, int numColumns) {
	textRender = renderer; // Para que la textura apunte al renderer del juego y no haya que pasarlo m�s veces al renderizar

	// Cargar textura
	SDL_Surface* surface = IMG_Load(filename); // Cargar imagen

	if (surface != nullptr) { // Comprobar que la imagen se ha cargado en surface

		texture = SDL_CreateTextureFromSurface(textRender, surface);
		SDL_FreeSurface(surface);

		// Guarda el ancho y alto de la textura en w y h respectivamente
		SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

		// Guarda el n�mero de filas y columnas de la textura
		numCols = numColumns;
		numRows = numFils;

		// Calcula y guarda el ancho y alto de cada frame
		fw = w / numCols;
		fh = h / numRows;

		originRect.w = fw;
		originRect.h = fh;

		return (texture != nullptr);
	}
	else
		return (false);
}

// Renderiza la textura entera en la posici�n y tama�o definidas por rectDest
void Textures::renderFullText(const SDL_Rect& rectDest, SDL_RendererFlip flip) {

	if (texture != nullptr)
		SDL_RenderCopyEx(textRender, texture, nullptr, &rectDest, 0, 0, flip); // SDL_Point*? declararlo o es necesio si o si?
}

// Renderiza el frame (row, col) en la posici�n y tama�o definida por rectDest
// Los frames empiezan en (0,0)
void Textures::renderFrame(const SDL_Rect& rectDest, unsigned int row, unsigned int col, SDL_RendererFlip flip) {

	if (texture != nullptr) {
		originRect.x = fw*col;
		originRect.y = fh*row;

		SDL_RenderCopyEx(textRender, texture, &originRect, &rectDest, 0, 0, flip);
	}
}