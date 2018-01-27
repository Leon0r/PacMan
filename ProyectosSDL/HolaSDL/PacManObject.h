#pragma once
#include "GameObject.h"
#include <fstream> // Para escritura y lectura
using namespace std;

class PlayState;

const int cellSize = 20; // Tamaño de las celdas (todas iguales)

class PacManObject :
	public GameObject
{
protected:
	PlayState* playState;
	

public:
	PacManObject(PlayState* playState);
	virtual ~PacManObject();

	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool handleEvent(SDL_Event& event) = 0;
	virtual void loadFromFile(ifstream& level) = 0;
	virtual void saveToFile(ofstream& level) = 0;
};