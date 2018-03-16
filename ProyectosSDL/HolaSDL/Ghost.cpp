#include "Ghost.h"
#include "PlayState.h" 

Ghost::Ghost(PlayState* playState, Textures* texture) : GameCharacter(playState, texture, 0)
{
	int frameX = rand() % 4;
	frameOrigX_ = frameX*2;
	frame.x = frameOrigX_;
}

Ghost::~Ghost()
{

}

void Ghost::update()
{
	GameCharacter::update();
	chooseRndDir();
}

// comprueba las dirs a las que puede ir el fantasma (de 0 a numDirs, reordenando el vector)
void Ghost::possibleDirs() {
	numDirs = directions.size();
	int i = 0;

	/*
	Tiene todas las direcciones en el vector
	Las va probando y, si no son válidas, intercambia la posicion con la última del vector
	porque aun no se ha probado seguro.
	NumDirs apunta al siguiente al ultimo, por lo que al hacer direcciones[numDirs - 1] entras el el último que no se ha probado
	Se resta (numDirs--) para dejar "descartadas" las dirs que no son válidas, en vez de inicializar el vector cada vez
	Y cuando acabe el bucle, las direcciones posibles deberian estar entre 0 y numDirs-1
	*/

	while (i < numDirs) {
		par aux = playState->getNextPosToroide(posAct, directions[i]);
		if (playState->isWall(aux)||playState->isGhost(aux)) {
			swap(directions[i], directions[numDirs - 1]);//intercambia 2 pares (el swap() de std de c++)
			numDirs--;
		}
		else
			i++;
	}

}

// Elige la sig direccin con un random
void Ghost::chooseRndDir() {
	possibleDirs();
	eraseBackDir();
	if (numDirs > 0) {
		// Genera la posicion de la nueva direccion con el modulo del random que sale
		int nextDir = (rand() % numDirs);
		dir.x = directions[nextDir].x;
		dir.y = directions[nextDir].y;
	}
}

// Elimina la direccion de la que viene si tiene mas direcciones posibles
void Ghost::eraseBackDir() {
	if (numDirs > 1) { // solo si hay al menos otra direccion
		int i = 0;
		// Busca la direccion contraria a la que viene y la descarta de igual forma que en Ghost::chooseRndDir()
		while ((i < numDirs) && (directions[i].x != -dir.x || directions[i].y != -dir.y)) i++;
		if (i < numDirs) {
			swap(directions[i], directions[numDirs - 1]);
			numDirs--;
		}
	}
}