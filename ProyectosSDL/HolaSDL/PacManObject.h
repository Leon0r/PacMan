#pragma once
#include <fstream> // Para escritura y lectura
#include "checkML.h"
#include "GameObject.h"
#include "PacmanError.h"
using namespace std;

class PlayState;

// struct "par" para manejar direcciones y posiciones como pares (x, y) de enteros
struct par
{
	int x;
	int y;
	par operator+(par a){
		par b = { x + a.x , y + a.y };
		return (b);
	}
	par operator=(par a) {
		par b = { a.x , a.y };
		return (b);
	}
};

const int cellSize = 20; // Tamaño de las celdas (todas iguales)

class PacManObject :
	public GameObject
{
protected:
	PlayState* playState;
	

public:
	PacManObject(PlayState* playState, Textures* textures);
	virtual ~PacManObject();

	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool handleEvent(SDL_Event& event) = 0;
	virtual void loadFromFile(ifstream& level) = 0;
	virtual void saveToFile(ofstream& level) = 0;
};