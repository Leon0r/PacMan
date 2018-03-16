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
	if (age < ADUL_AGE || timeExit > 0)
		Ghost::update();
	else if (age < DEATH_AGE) {
		selectDir();
		GameCharacter::update();
	}
	else if (!dead)
		dieOld();
}

bool SmartGhost::handleEvent(SDL_Event& event)
{
	return true;
}

void SmartGhost::fillNewSmartGhost(SmartGhost* ghost)
{
	ghost->age = 0;
	par aux;
	int p = rand() % numDirs;
	///REVISAR
	aux = directions[p] + posAct;
	//la posicion libre
	ghost->posAct.x = aux.x;
	ghost->posAct.y = aux.y;
	ghost->posIni.x = ghost->posAct.x;
	ghost->posIni.y = ghost->posAct.y;
}

void SmartGhost::giveBirth()
{
	SmartGhost* ghost = new SmartGhost(playState, texture);
	fillNewSmartGhost(ghost);

	playState->newSmartGhost(ghost);
}

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