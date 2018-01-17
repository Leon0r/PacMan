#pragma once
#include "PacmanError.h"

class SDLError :
	public PacmanError
{

public:
	SDLError(string message);
	~SDLError();
};