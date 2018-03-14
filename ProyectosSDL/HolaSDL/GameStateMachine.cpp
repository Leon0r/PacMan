#include "GameStateMachine.h"

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
}

GameState* GameStateMachine::currentState()
{
	return states.top();
}

void GameStateMachine::changeState()
{

}

void GameStateMachine::pushState(GameState* state)
{
	states.push(state);
}

void GameStateMachine::popState()
{
	/// delete states.top();
	states.pop();
}
