#pragma once
#include <string>
using namespace std;


class Fio {
private:
	string surname;
	string name;
	string patronymic;

public:
	bool SetSurname(string bufString);
	bool SetName(string bufString);
	bool SetPatronymic(string bufString);

	string GetSurname();
	string GetName();
	string GetPatronymic();

	bool Init(string bufSurname, string bufName, string bufPatronymic);
	bool Read();
	void Display();
};
