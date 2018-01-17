#pragma once
#include "GameCharacter.h"

class Ghost :
	public GameCharacter
{
public:
	Ghost(PlayState* playState);
	virtual ~Ghost();

	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& event);
	virtual void loadFromFile(ifstream& level) { GameCharacter::loadFromFile(level); }
	virtual void saveToFile(ofstream& level) { GameCharacter::saveToFile(level);}
};