#pragma once
#include <vector>
#include "checkML.h"
#include "GameCharacter.h"

const unsigned int NUM_DIRS = 4; // Numero posible de dirs

class Ghost :
	public GameCharacter
{
protected:
	int numDirs = 4; // Numero de direcciones posibles
	// Inicializa el vector de direcciones a las 4 posibles (arriba, abajo, izquierda, derecha)
	vector<par> directions{ { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } };
	// Comprueba las dirs a las que puede ir el fantasma (de 0 a numDirs, reordenando el vector)
	virtual void possibleDirs(); 
	// Elige la sig direccin con un random
	void chooseRndDir();
	// Elimina de las posibilidades la direccion de la que viene si es posible
	void eraseBackDir(); 

public:
	Ghost(PlayState* playState, Textures* textures);
	virtual ~Ghost();

	virtual void update();
	virtual void loadFromFile(ifstream& level) { GameCharacter::loadFromFile(level); }
	virtual void saveToFile(ofstream& level) { level << "0 "; GameCharacter::saveToFile(level); }
};