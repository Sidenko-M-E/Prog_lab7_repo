#pragma once
#include "Fio.h"

class Human {
private:
	int id;
	int age;
	int height;
	double weight;
	char gender;

public:
	Fio fioField;

	bool SetId(int buf);
	bool SetAge(int buf);
	bool SetHeight(int buf);
	bool SetWeight(double buf);
	bool SetGender(char buf);

	int GetId();
	int GetAge();
	int GetHeight();
	double GetWeight();
	char GetGender();

	bool Init(int bufId, int bufAge, int bufHeight, double bufWeight, char bufGender, Fio bufFio);
	bool Read();
	void Display();
};
