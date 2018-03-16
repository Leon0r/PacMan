#pragma once
#include "checkML.h"
#include "GameState.h"
#include "GameMap.h"
#include "Pacman.h"
#include "Ghost.h"
#include "SmartGhost.h"

const int FRAME_RATE = 100; // A menor tiempo de espera entre frames, mayor la velocidad del bucle
const int MAX_SMART_GHOSTS = 5;

class PlayState :
	public GameState
{
private:
	list <GameObject*>::iterator it;
	int level_;
	int numSmartGhosts = 0;

	uint32_t startTime, frameTime; // Control del tiempo de repeticion del bucle

	Pacman * pacman;
	GameMap* map;
	// Devuelve la sig pos en esa direccion teniendo en cuenta el toroide
	unsigned int Right(const int posX);
	unsigned int Left(const int posX);
	unsigned int Up(const int posY);
	unsigned int Down(const int posY);

public:
	PlayState(Game* game, int level);
	PlayState(Game* game);
	virtual ~PlayState() {}

	void update();
	void render();
	bool handleEvent(SDL_Event& event);
	// newGame = true si es partida desde nivel limpio 
	void loadGame(string fileName, bool newGame); 
    // Guarda en un archivo la información del juego
	void saveToFile();

	// Permite hacerlo porque la declaracion del struct 'par' esta en pacmanObject.h fuera de las clases, 
	// por lo que se puede utilizar desde cualquier sitio que incluya a PacmanObject.h o alguna clase que herede de el

	// Devuelve la sig posicion del toroide en la direccion 'dir'
	par getNextPosToroide(const par pos, const par dir);
	// Devuelve la posAct del Pacman
	par getPacmanPos() { return pacman->getPosAct(); }

	// Devuelve true si las posición 'pos' hay muro
	bool isWall(const par pos);
	// Comprueba si hay un fantasma el la posAct del Pacman
	bool isGhost();
	// Comprueba si hay un fantasma el la posicion pos
	bool isGhost(par pos);
	// Comprueba si hay un SmartGhost el la posicion pos
	bool isSmartGhost(par pos);
	// Devuelve true si hay comida o vitamina en esa posición
	bool isEatable(const par pos, int& type);
	// Devuelve true si se puede comer el smartGhost por estar muerto
	bool isSmartGhostEatable(par pos);
	// Cambia la casilla vacias y resta comida
	void wasEaten(const par pos);
	// Determina el efecto de la colisión
	void collisionHandler();
	// Comprueba si has ganado
	bool winLevel() { return (map->getNumMaxFood() <= 0); };
	// Pasa al estado EndState al morir
	void endGame();
	// Escribe en consola los puntos y las vidas de Pacman
	void consoleHUD();
	// Añade un SmartGhost a la lista de GameObjects
	void newSmartGhost(SmartGhost* ghost);
	// Resta al total de SmartGhosts en pantalla
	void dismissDeathSG() { numSmartGhosts--; }
	// Devuelve el numero de SmartGhosts en pantalla
	int getNumSG() { return numSmartGhosts; }
};

