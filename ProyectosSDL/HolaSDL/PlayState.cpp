#include "PlayState.h"
#include "Game.h"


PlayState::PlayState(Game* game, char* level) : GameState(game)
{	
	loadGame(level);
}

PlayState::~PlayState()
{
	
}

void PlayState::update()
{
	
}

void PlayState::render() {
	GameState::render();
	// Como el pacman esta delante del mapa en la lista, 
	//se pinta por debajo del mapa y no se ve
	pacman->render(); 
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

void PlayState::saveToFile() {

}

// devuelve la sig posicion del toroide en la direccion 'dir'
par PlayState::getNextPosToroide(const par pos, const par dir) {
	par aux = pos;

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

