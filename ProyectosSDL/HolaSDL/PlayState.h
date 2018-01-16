#pragma once
#include "GameState.h"
class PlayState :
	public GameState
{
public:
	PlayState(Game* game);
	~PlayState();

	void update();
};

