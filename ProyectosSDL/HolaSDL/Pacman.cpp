#include "Pacman.h"
#include "PlayState.h" 

Pacman::Pacman(PlayState* playState, Textures* texture) : GameCharacter(playState, texture, 10)
{

}

Pacman::~Pacman()
{

}

void Pacman::update() 
{
	changeDir();
	if (playState->isGhost())
		playState->collisionHandler();
	GameCharacter::update();
	if (playState->isGhost())
		playState->collisionHandler();
	eatFood();

	if (hasVitamin())
		energy--;
}

bool Pacman::handleEvent(SDL_Event& event) 
{
	bool handled = false;

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_UP) {
			nextDir = { 0, -1 };
			handled = true;
		}
		else if (event.key.keysym.sym == SDLK_DOWN) {
			nextDir = { 0, 1 };
			handled = true;
		}
		else if (event.key.keysym.sym == SDLK_LEFT) {
			nextDir = { -1, 0 };
			handled = true;
		}
		else if (event.key.keysym.sym == SDLK_RIGHT) {
			nextDir = { 1, 0 };
			handled = true;
		}
	}
	return handled;
}

// Come comida y vitaminas
void Pacman::eatFood()
{
	int type;
	if (playState->isEatable(posAct, type))
	{
		if (playState->isEatable(posAct, type) && type == 3)
			energy = ENERGY_VIT;
		points_++;
		playState->wasEaten(posAct);
	}
} 

void Pacman::death()
{
	if (lifes > 0) 
	{
		lifes--;
		GameCharacter::death();
	}
	else
		playState->endGame();
}

// Lee lo necesario del archivo para cargar el Pacman
void Pacman::loadFromFile(ifstream& level)
{
	GameCharacter::loadFromFile(level);
	if (!level.eof()) // Si es un archivo de guardado lee también la energía y las vidas
		level >> energy >> lifes;
}

// Guarda en un archivo la información del Pacman
void Pacman::saveToFile(ofstream& level)
{
	GameCharacter::saveToFile(level);
	level << " " << energy << " " << lifes;
}

void Pacman::changeDir(){

	par aux = playState->getNextPosToroide(posAct, nextDir);

	if (!playState->isWall(aux)) { dir = nextDir; }
}