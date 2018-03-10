#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* game, char* level) : GameState(game)
{	
	loadGame(level);
}

PlayState::~PlayState()
{
	
}

void PlayState::update() {
	startTime = SDL_GetTicks();

	GameState::update();

	frameTime = SDL_GetTicks() - startTime; // Calcula el tiempo del update del playState

	// Si no ha pasado el tiempo definido en FRAME_RATE, hay delay de lo que falta
	if (frameTime<FRAME_RATE) SDL_Delay(FRAME_RATE - frameTime);
}

void PlayState::render() {
	GameState::render();
	// Como el pacman esta delante del mapa en la lista, 
	//se pinta por debajo del mapa y no se ve
	pacman->render(); 
}

bool PlayState::handleEvent(SDL_Event & event)
{
	bool handled = false;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p) {
			game->loadPauseState();
			handled = true;
	}
	else {
		handled = GameState::handleEvent(event);
	}
	return handled;
}

void PlayState::loadGame(string level)
{
	ifstream file(level);

	map = new GameMap(this, game->getTexture(5));
	objects.push_front(map);
	dynamic_cast<GameMap*>(objects.front())->loadFromFile(file);

	int numGhosts, typeGhost;
	file >> numGhosts;

	for (int i = 0; i < numGhosts; i++) {
		file >> typeGhost;
		if (typeGhost == 0) {
			objects.push_back(new Ghost(this, game->getTexture(6)));
			dynamic_cast<Ghost*>(objects.back())->loadFromFile(file);
		}
		else if (typeGhost == 1) {
			objects.push_back(new SmartGhost(this, game->getTexture(6)));
			dynamic_cast<SmartGhost*>(objects.back())->loadFromFile(file);
		}
	}

	pacman = new Pacman(this, game->getTexture(6));
	objects.push_front(pacman);
	dynamic_cast<Pacman*>(objects.front())->loadFromFile(file);

	file.close();
}

void PlayState::saveToFile() 
{

}

// Devuelve la sig posicion del toroide en la direccion 'dir'
par PlayState::getNextPosToroide(const par pos, const par dir) {
	par aux;
	aux.x = pos.x;
	aux.y = pos.y;

	if (dir.x == 1)
		aux.x = Right(pos.x);
	else if (dir.x == -1)
		aux.x = Left(pos.x);
	else if (dir.y == 1)
		aux.y = Down(pos.y);
	else if (dir.y == -1)
		aux.y = Up(pos.y);
	return aux;
}

// Devuelve true si las posición 'pos' hay muro
bool PlayState::isWall(const par pos) 
{
	return(map->getCellType(pos.y, pos.x) == 1); 
}

// Comprueba si hay un fantasma el la posAct del Pacman
bool PlayState::isGhost()
{
	it = objects.begin();
	it++; it++;

	while ((it != objects.end()) &&
		(pacman->getPosAct().x != dynamic_cast<GameCharacter*>(*it)->getPosAct().x
		|| pacman->getPosAct().y != dynamic_cast<GameCharacter*>(*it)->getPosAct().y))
		it++;

	return (!(it == objects.end()));
}

// Devuelve true si hay comida o vitamina en esa posición
bool PlayState::isEatable(const par pos, int& type)
{
	type = map->getCellType(pos.y, pos.x);
	return(type == 2 || type == 3);
}

// Cambia la casilla vacias y resta comida
void PlayState::wasEaten(const par pos)
{
	map->fillCell(pos.y, pos.x, 0);
	map->lessFood();
}

// Determina el efecto de la colisión
void PlayState::collisionHandler()
{
	if (pacman->hasVitamin())
		dynamic_cast<GameCharacter*>(*it)->death();
	else
		pacman->death();
}

// Devuelve la sig pos en esa direccion teniendo en cuenta el toroide
unsigned int PlayState::Right(const int posX)
{
	if (posX + 1 >= map->getNumCols())
		return(0);
	return(posX + 1);
}

unsigned int PlayState::Left(const int posX)
{
	if (posX - 1 < 0)
		return(map->getNumCols() - 1);
	return(posX - 1);
}

unsigned int PlayState::Up(const int posY)
{
	if (posY - 1 < 0)
		return(map->getNumRows() - 1);
	return(posY - 1);
}

unsigned int PlayState::Down(const int posY)
{
	if (posY + 1 >= map->getNumRows())
		return(0);
	return(posY + 1);
}

