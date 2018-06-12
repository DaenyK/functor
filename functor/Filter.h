#pragma once
#include "Human.h"
class Filter {
private:
	string key; //указание свойства по которому будет фильтрация
	string svalue;
	int ivalue;
public:
	Filter(string key, string svalue){
		this->key = key;
		this->svalue;
	}
	Filter(string key, int ivalue) {
		this->key = key;
		this->ivalue;
	}

	bool operator() (Human h) {
		if (this->key == "name")
		{
			if (this->svalue == h.getName())
				return true;
		}
		else if (this->key == "sname")
		{
			if (this->svalue == h.getSname())
				return true;
		}
		else if (this->key == "age")
		{
			if (this->ivalue == h.getAge())
				return true;
		}
		return false;
	}

};
