#include "GameCharacter.h"
#include "PlayState.h" 

GameCharacter::GameCharacter(PlayState* playState, Textures* texture, int frameX) : PacManObject(playState, texture)
{
	frameOrigX_ = frameX;
	frame.x = frameOrigX_;
	frame.y = 0;
}


GameCharacter::~GameCharacter()
{

}

void GameCharacter::update() {
	par aux = playState->getNextPosToroide(posAct, dir);

	if(!playState->isWall(aux))
		posAct = aux;
}

void GameCharacter::render()
{
	animate();
	destRect.x = destRect.w*posAct.x;
	destRect.y = destRect.h*posAct.y;

	texture->renderFrame(destRect, frame.y, frame.x);
}

bool GameCharacter::handleEvent(SDL_Event& event)
{
	return true;
}

// Hace las animaciones de los personajes
void GameCharacter::animate()
{
	if (dir.x == 1) // dcha
		frame.y = 0;
	else if (dir.x == -1) //izqu
		frame.y = 2;

	if (dir.y == -1) // arriba
		frame.y = 3;
	else if (dir.y == 1) // abajo
		frame.y = 1;

	if (switchAnim)
		frame.x = frameOrigX_;
	else
		frame.x = frameOrigX_ + 1;

	switchAnim = !switchAnim;
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

// Devuelve a su posIni al personaje
void GameCharacter::death()
{
	posAct.x = posIni.x;
	posAct.y = posIni.y;
}