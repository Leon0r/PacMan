#pragma once
#include <vector>
#include "checkML.h"
#include "GameCharacter.h"

const unsigned int NUM_DIRS = 4; // Numero posible de dirs

class Ghost :
	public GameCharacter
{
protected:
	int numDirs = 4; // numero de direcciones posibles
	// inicializa el vector de direcciones a las 4 posibles (arriba, abajo, izquierda, derecha)
	vector<par> directions{ { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } };
	virtual void possibleDirs(); // comprueba las dirs a las que puede ir el fantasma (de 0 a numDirs, reordenando el vector)
	void chooseRndDir(); // Elige la sig direccin con un random
	void eraseBackDir(); // Elimina de las posibilidades la direccion de la que viene si es posible

public:
	Ghost(PlayState* playState, Textures* textures);
	virtual ~Ghost();

	virtual void update();
	virtual bool handleEvent(SDL_Event& event);
	virtual void loadFromFile(ifstream& level) { GameCharacter::loadFromFile(level); }
	virtual void saveToFile(ofstream& level) { GameCharacter::saveToFile(level);}
};