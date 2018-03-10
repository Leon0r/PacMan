#pragma once
#include "checkML.h"
#include "GameCharacter.h"

const int ENERGY_VIT = 200; // Tiempo que actúa la vitamina
class Pacman :
	public GameCharacter
{
private:
	unsigned int points = 0,
				 energy = 0,
				 lifes = 3;

	par nextDir = { 0,0 }; // buffer de direccion

	void changeDir();

public:
	Pacman(PlayState* playState, Textures* textures);
	~Pacman();

	void update();
	bool handleEvent(SDL_Event& event);
	// Come comida y vitaminas
	void eatFood();
	// Comprueba si tiene vitamina
	bool hasVitamin() { return (energy > 0); }
	// Le resta vida al pacman
	void death();
	// Lee lo necesario del archivo para cargar el Pacman
	void loadFromFile(ifstream& level);
	// Guarda en un archivo la información del Pacman
	void saveToFile(ofstream& level);
};

