#pragma once
#include "GameObject.h"
#include "PlayState.h"
#include <fstream> // Para escritura y lectura
using namespace std;

class PacManObject :
	public GameObject
{
protected:
	PlayState* playState;
	int cellSize; // Tama�o de las celdas (todas iguales)

public:
	PacManObject();
	~PacManObject();
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool handleEvent(SDL_Event& event) = 0;
	virtual void loadFromFile(ifstream& level) = 0;
	virtual void saveToFile(ofstream& level) = 0;
};