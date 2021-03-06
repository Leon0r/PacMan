#pragma once
#include "checkML.h"
#include "PacManObject.h"

class GameCharacter :
	public PacManObject
{
protected:
	par posIni, // Pos inicial del character para reiniciarla al morir
		posAct, // Pos actual del character
		dir;    // Direccion actual del character

	bool switchAnim = false;
	int frameOrigX_;
	par frame;
	/// Coordenadas en la textura del frame (esquina sup izquierda) concreto a renderizar
	/// Como todos los personajes tienen las animaciones colocadas igual, 
	/// solo hace falta saber donde empieza cada una

public:
	GameCharacter(PlayState* playState, Textures* textures, int frameX);
	virtual ~GameCharacter();

	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& event);

	// Hace las animaciones de los personajes
	virtual void animate(); 

	// Lee lo necesario del archivo para cargar el GameCharacter
	virtual void loadFromFile(ifstream& level);
	// Escribe posAct, posIni, dir del GameCharacter
	virtual void saveToFile(ofstream& level);

	// Devuelve a su posIni al personaje
	virtual void death();
	// Devuelve la posicion actual del personaje
	virtual par getPosAct() { return posAct; }
};