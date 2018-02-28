#pragma once
#include "checkML.h"
#include "PacmanError.h"

class FileNotFoundError :
	public PacmanError
{

public:
	FileNotFoundError(string message);
	~FileNotFoundError();
};

