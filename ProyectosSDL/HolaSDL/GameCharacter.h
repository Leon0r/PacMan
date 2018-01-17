#pragma once
#include "PacManObject.h"

// struct "par" para manejar direcciones y posiciones como pares (x, y) de enteros
struct par
{
	int x;
	int y;
};

class GameCharacter :
	public PacManObject
{
protected:
	par posIni, // Pos inicial del character para reiniciarla al morir
		posAct, // Pos actual del character
		dir;    // Direccion actual del character

	par frame;
	/// Coordenadas en la textura del frame (esquina sup izquierda) concreto a renderizar
	/// Como todos los personajes tienen las animaciones colocadas igual, 
	/// solo hace falta saber donde empieza cada una

public:
	GameCharacter(PlayState* playState);
	virtual ~GameCharacter();

	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& event);
	// Lee lo necesario del archivo para cargar el GameCharacter
	virtual void loadFromFile(ifstream& level);
	// Escribe posAct, posIni, dir del GameCharacter
	virtual void saveToFile(ofstream& level);
};