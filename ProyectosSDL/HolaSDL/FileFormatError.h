#pragma once
#include "PacmanError.h"

class FileFormatError :
	public PacmanError
{

public:
	FileFormatError(string message);
	~FileFormatError();
};