#pragma once
#include <vector>
#include "GameCharacter.h"

const unsigned int NUM_DIRS = 4; // Numero posible de dirs

class Ghost :
	public GameCharacter
{
protected:
	// inicializa el vector de direcciones a las 4 posibles (arriba, abajo, izquierda, derecha)
	vector<par> directions{ { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } };
public:
	Ghost(PlayState* playState);
	virtual ~Ghost();

	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& event);
	virtual void loadFromFile(ifstream& level) { GameCharacter::loadFromFile(level); }
	virtual void saveToFile(ofstream& level) { GameCharacter::saveToFile(level);}
};