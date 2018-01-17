#pragma once
#include <stdexcept>
using namespace std;

class PacmanError:
	public logic_error
{
public:

	PacmanError(string message);
	virtual ~PacmanError();

	virtual string what() { return logic_error::what(); }
};

