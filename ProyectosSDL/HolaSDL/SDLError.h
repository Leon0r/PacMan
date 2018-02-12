#pragma once
#include "checkML.h"
#include "PacmanError.h"

class SDLError :
	public PacmanError
{

public:
	SDLError(string message);
	~SDLError();
};