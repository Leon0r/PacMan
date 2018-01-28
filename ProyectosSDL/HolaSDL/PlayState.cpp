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

void PlayState::loadGame(string level)
{
	ifstream file(level);

	objects.push_front(new GameMap(this, game->getTexture(5)));
	dynamic_cast<GameMap*>(objects.front())->loadFromFile(file);

	int numGhosts;
	file >> numGhosts;

	for (int i = 0; i < numGhosts; i++) {
		objects.push_back(new Ghost(this));
		dynamic_cast<Ghost*>(objects.back())->loadFromFile(file);
	}

	objects.push_front(new Pacman(this));
	dynamic_cast<Pacman*>(objects.front())->loadFromFile(file);

	file.close();
}

par PlayState::getNextPosToroide(par pos, par dir) {
	return pos;
}
