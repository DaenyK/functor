#pragma once
#include "Human.h"

class findByName {
private:
	string name;
public:
	findByName(string name)
	{
		this->name = name;
	}

	bool operator() (const Human& h)
	{
		return (this->name == h.getName());
	}
};
