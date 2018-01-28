#pragma once
#include "checkML.h"
#include "PacManObject.h"

class GameMap :
	public PacManObject
{
private:
	unsigned int numRowMap,
				 numColMap,
				 numMaxFood = 0;

	//Tipos de celda del mapa de juego
	enum MapCell {Empty, Wall, Food, Vitamin};
	MapCell** map; // Matriz de punteros

public:
	GameMap(PlayState* playState, Textures* texture);
	~GameMap();
	
	void update();
	// Pinta el mapa en pantalla (renderCopy de las celdas)
	void render();
	bool handleEvent(SDL_Event& event);
	// Lee lo necesario del archivo level para cargar el mapa
	void loadFromFile(ifstream& level);
	// Rellena una celda con el tipo type
	void fillCell(int row, int col, int type);
	// Escribe los datos del mapa en el archivo level (solo los datos del mapa)
	void saveToFile(ofstream& level);

	// Devuelve el número de comida (food y vitamins) del mapa
	int getNumMaxFood() { return numMaxFood; }
	// Devuelve el tipo de la celda
	int getCellType(int row, int col) { return(static_cast<int>(map[row][col])); }
	// Devuelve el numero de filas
	int getNumRows() { return numRowMap; }
	// Devuelve el numero de columnas
	int getNumCols() { return numColMap; }
};

