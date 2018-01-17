#pragma once
#include "PacmanError.h"

class FileNotFoundError :
	public PacmanError
{

public:
	FileNotFoundError(string message);
	~FileNotFoundError();
};

