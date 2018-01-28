#pragma once
#include "GameState.h"
#include "GameMap.h"
#include "Pacman.h"
#include "Ghost.h"
#include "SmartGhost.h"

class PlayState :
	public GameState
{
private:
	Pacman * pacman;
	GameMap* map;
	// Devuelve la sig pos en esa direccion teniendo en cuenta el toroide
	unsigned int Right(const int posX);
	unsigned int Left(const int posX);
	unsigned int Up(const int posY);
	unsigned int Down(const int posY);

public:
	PlayState(Game* game, char* level);
	~PlayState();

	void render();
	void loadGame(string level);
	void saveToFile();

	// Permite hacerlo porque la declaracion del struct 'par' esta en pacmanObject.h fuera de las clases, 
	//por lo que se puede utilizar desde cualquier sitio que incluya a PacmanObject.h o alguna clase que herede de el

	par getNextPosToroide(const par pos, const par dir); // devuelve la sig posicion del toroide en la direccion 'dir'
	bool hayMuro(const par pos); // true si la posicion 'pos' hay muro
};

