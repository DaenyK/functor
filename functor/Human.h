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
	string getName() { return name; }
	string getSname() { return sname; }
	int getAge() { return age; }
};