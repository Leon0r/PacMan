#pragma once
#include "checkML.h"
#include "PacmanError.h"

class FileFormatError :
	public PacmanError
{

public:
	FileFormatError(string message);
	~FileFormatError();
};