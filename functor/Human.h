#pragma once
#include "Headers.h"

class Human {
private:
	string name;
	string sname;
	int age;
public:
	Human(string name, string sname, int age) {
		this->name = name;
		this->sname = sname;
		this->age = age;
	}
	string getName() const{ return this->name; }
	string getSname()const { return this->sname; }
	int getAge()const { return this->age; }
};