#include "SmartGhost.h"
#include "PlayState.h" 

SmartGhost::SmartGhost(PlayState* playState, Textures* texture) : Ghost(playState, texture)
{
	frameOrigX_ = 8;
	frame.x = frameOrigX_;
}

SmartGhost::~SmartGhost()
{
}

void SmartGhost::update()
{
	timeExit--;
	if (age < ADULT_AGE || timeExit > 0)
		Ghost::update();
	else if (age < DEATH_AGE) {
		selectDir();
		canGiveBirth();
		GameCharacter::update();
	}
	else if (!dead)
		dieOld();
}

// Rellena los campos basicos de un SmartGhost
void SmartGhost::fillNewSmartGhost(SmartGhost* ghost)
{
	ghost->age = 0;
	par aux;
	int p = rand() % numDirs;

	aux.x = directions[p].x + posAct.x;
	aux.y = directions[p].y + posAct.y;

	//la posicion libre
	ghost->posAct.x = aux.x;
	ghost->posAct.y = aux.y;
	ghost->posIni.x = ghost->posAct.x;
	ghost->posIni.y = ghost->posAct.y;
}

// Completa los datos de un SmartGhost y llama al PlayState para crearlo
void SmartGhost::giveBirth()
{
	SmartGhost* ghost = new SmartGhost(playState, texture);
	fillNewSmartGhost(ghost);

	playState->newSmartGhost(ghost);
}

// Selecciona la direccion del movimiento
void SmartGhost::selectDir()
{
	targetPos = playState->getPacmanPos();
	possibleDirs();

	if (numDirs > 0) { // Solo busca dir si tiene mas de una posibilidad
					   // Solo quita hacia atras si esta en cruces
					   // Principalmente es para que no parpadee en la celda donde empieza
		int dirAux;

		int dist = 30000;
		int aux;
		for (int i = 0; i < numDirs; i++) {
			{
				// Calcula la coordenada que le deja mas "cerca" del pacman
				aux = abs((posAct.x + directions[i].x) - targetPos.x) +
					abs((posAct.y + directions[i].y) - targetPos.y);

				// Guarda la pos de la dir mas cercana
				if (aux < dist) {
					dist = aux;
					dirAux = i;
				}
			}
		}
		dir.x = directions[dirAux].x;
		dir.y = directions[dirAux].y;
	}
}

void SmartGhost::canGiveBirth()
{
	if (!dead && age > ADULT_AGE) {
		int i = 0;
		par aux;
		aux.x = posAct.x + directions[i].x;
		aux.y = posAct.y + directions[i].y;

		while (i < numDirs && playState->isSmartGhost(aux)) {
			i++;
			aux.x = posAct.x + directions[i].x;
			aux.y = posAct.y + directions[i].y;
		}

		if (i < numDirs) {
			int rnd = rand() % 3;
			if (rnd == 0) giveBirth();
		}
	}
}

// Desactiva completamente el SmartGhost
void SmartGhost::dieOld() {
	dead = true;
	dir = { 0,0 };
}

// Lee lo necesario del archivo para cargar el SmartGhost
void SmartGhost::loadFromFile(ifstream& level)
{
	GameCharacter::loadFromFile(level);
	level >> age;
}

// Guarda en un archivo la información del Pacman
void SmartGhost::saveToFile(ofstream& level)
{
	level << "1 ";
	GameCharacter::saveToFile(level);
	level << " " << age;
}