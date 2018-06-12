#include "Filter.h"
#include "SortByKey.h"
#include "findByName.h"

void print(Human h) {
	cout << h.getName() << "\t" << h.getSname() << "\t" << h.getAge() << endl;
}

int main() {
	setlocale(LC_ALL, "russian");
	short a, answer;

	do {
		cout << "which task?";
		cin >> a;
		system("cls");
		switch (a) {
		case 1:
		{
			vector<Human>vh;
			vh.push_back(Human("lana", "ray", 29));
			vh.push_back(Human("john", "snow", 24));
			vh.push_back(Human("arya", "stark", 15));

			auto it = vh.erase(remove_if(vh.begin(), vh.end(), Filter("name", "john")), vh.end());
			for_each(vh.begin(), vh.end(), print);
			cout << endl << endl;

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
		}break;

		case 2: {
			vector<Human>vh;
			vh.push_back(Human("lana", "ray", 29));
			vh.push_back(Human("john", "snow", 24));
			vh.push_back(Human("arya", "stark", 15));
			string key;
			cout << "введите ключ, по которому будет произведена сортировка: ";
			cin >> key;

			sort(vh.begin(), vh.end(), SortByKey(key));
			for_each(vh.begin(), vh.end(), print);
		}break;

		case 3:
		{
			vector<Human>vh;
			vh.push_back(Human("lana", "ray", 29));
			vh.push_back(Human("john", "snow", 24));
			vh.push_back(Human("arya", "stark", 15));

			string name;
			cout << "введите имя, чтобы вывести полную информацию: ";
			cin >> name;

			auto it = find_if(vh.begin(), vh.end(), findByName(name));
			if (it != vh.end())
				cout << it->getName() << "\t" << it->getSname() << "\t" << it->getAge() << endl;


		}break;
		}
		cout << "continue?1/0";
		cin >> answer;
	} while (answer != 0);
		system("pause");
}