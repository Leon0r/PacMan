#include "FileNotFoundError.h"

FileNotFoundError::FileNotFoundError(string message): PacmanError(message)
{
}

FileNotFoundError::~FileNotFoundError()
{
}