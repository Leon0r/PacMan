#pragma once
#include <stack>
#include "checkML.h"
#include "EndState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "PlayState.h"

using namespace std;

class GameStateMachine
{
	stack <GameState*> states;

public:
	GameStateMachine();
	~GameStateMachine();

	GameState* currentState();
	void changeState();
	void pushState(GameState* state);
	void popState();

	size_t getSize() { return states.size(); }
};