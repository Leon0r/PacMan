#pragma once
#include "GameCharacter.h"

const int ENERGY_VIT = 200; // Tiempo que act�a la vitamina
class Pacman :
	public GameCharacter
{
private:
	unsigned int points = 0,
				 energy = 0,
				 lifes = 3;
public:
	Pacman(PlayState* playState);
	~Pacman();

	void update();
	void render();
	bool handleEvent(SDL_Event& event);
	// Lee lo necesario del archivo para cargar el Pacman
	void loadFromFile(ifstream& level);
	// Guarda en un archivo la informaci�n del Pacman
	void saveToFile(ofstream& level);
};

