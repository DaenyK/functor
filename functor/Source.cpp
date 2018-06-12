#include "Filter.h"

void print(Human h) {
	cout << h.getName() << "\t" << h.getSname() << "\t" << h.getAge() << endl;
}

int main() {
	setlocale(LC_ALL, "russian");

	vector<Human>vh;
	vh.push_back(Human("lana", "ray", 29));
	vh.push_back(Human("john", "snow", 24));
	vh.push_back(Human("arya", "stark", 15));

	string key, svalue;
	int ivalue;
	cout << "введите ключ по которому будет сделана фильтрация(name, sname, age): ";
	cin >> key;
	if (key == "name")
	{
		cout << "\nвведите строковое значение для фильтрации: "; cin >> svalue;
		auto it = vh.erase(remove_if(vh.begin(), vh.end(), Filter("name", svalue)), vh.end());
		for_each(vh.begin(), vh.end(), print);
	}
	else if (key == "sname")
	{
		cout << "\nвведите строковое значение для фильтрации: "; cin >> svalue;
		auto it = vh.erase(remove_if(vh.begin(), vh.end(), Filter("sname", svalue)), vh.end());
		for_each(vh.begin(), vh.end(), print);
	}
	else if (key == "age")
	{
		cout << "\nвведите числовое значение для фильтрации: "; cin >> ivalue;
		auto it = vh.erase(remove_if(vh.begin(), vh.end(), Filter("age", ivalue)), vh.end());
		for_each(vh.begin(), vh.end(), print);
	}
	else {
		cout << "\nошибка, вы ввели неправильное значение для ключа\n";
	}

	system("pause");
}