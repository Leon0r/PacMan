#include "GameCharacter.h"
#include "PlayState.h" 

GameCharacter::GameCharacter(PlayState* playState, Textures* texture) : PacManObject(playState, texture)
{
	frame.x = 0;
	frame.y = 0;
}


GameCharacter::~GameCharacter()
{

}

void GameCharacter::update() {
	posAct = playState->getNextPosToroide(posAct, dir);
}

void GameCharacter::render()
{
	destRect.x = destRect.w*posAct.x;
	destRect.y = destRect.h*posAct.y;

	texture->renderFrame(destRect, frame.y, frame.x);
}

bool GameCharacter::handleEvent(SDL_Event& event)
{
	return true;
}

// Lee lo necesario del archivo para cargar el GameCharacter
void GameCharacter::loadFromFile(ifstream& level)
{
	// Inicializa las posiciones inicial y actual a la pos de entrada
	level >> posAct.x;
	level >> posAct.y;
	level >> posIni.x;
	level >> posIni.y;
	// Inicializa la direccion de movimiento
	level >> dir.x;
	level >> dir.y;
}

// Escribe posAct, posIni, dir del GameCharacter
void GameCharacter::saveToFile(ofstream& level)
{
	level << posAct.x << " " << posAct.y << " "
		<< posIni.x << " " << posIni.y << " "
		<< dir.x << " " << dir.y;
}