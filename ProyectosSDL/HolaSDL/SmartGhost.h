#pragma once
#include "Ghost.h"
#include "checkML.h"

const int ADULT_AGE = 40;
const int DEATH_AGE = 300;
const int TIME_SALIDA = 30;

class SmartGhost :
	public Ghost
{
protected:
	unsigned int age;
	int timeExit = TIME_SALIDA;
	bool dead = false;
	par targetPos;

	// Rellena los campos basicos de un SmartGhost
	virtual void fillNewSmartGhost(SmartGhost* ghost);
	// Completa los datos de un SmartGhost y llama al PlayState para crearlo
	virtual void giveBirth();
	// Selecciona la direccion del movimiento
	virtual void selectDir();
	// Comprueba las condiciones para que sea posible tener hijos
	virtual void canGiveBirth();
	// Desactiva completamente el SmartGhost
	virtual void dieOld();

public:
	SmartGhost(PlayState* playState, Textures* textures);
	virtual ~SmartGhost();

	void update();

	// Devuelve el valor del booleano dead
	bool isDead() { return dead; }
	// Comprueba si es adulto
	bool isAdult() { return(age > ADULT_AGE); }
	// Reinicia timeExit y llama death
	virtual void death() { timeExit = TIME_SALIDA; GameCharacter::death(); }
	// Lee lo necesario del archivo para cargar el SmartGhost
	void loadFromFile(ifstream& level);
	// Guarda en un archivo la información del SmartGhost
	void saveToFile(ofstream& level);
};

