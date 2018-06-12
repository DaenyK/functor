#pragma once
#include "Human.h"
class SortByKey {
private:
	string key;
public:
	SortByKey(string key) { this->key = key; }

	bool operator() (const Human& h1, const Human& h2)
	{
		if (key == "name")
		{
			return h1.getName() < h2.getName();
		}
		else if (key == "sname")
		{
			return h1.getSname() < h2.getSname();
		}
		else if (key == "age")
		{
			return h1.getAge() < h2.getAge();
		}
	}
};
