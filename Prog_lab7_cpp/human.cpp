#include "Human.h"
#include <cmath>
#include <string>
#include <iostream>


bool Human::SetId(int buf)
{
	if (buf < 0 || buf > 9999)
		return (true);
	else
	{
		id = buf;
		return (false);
	}
}

bool Human::SetAge(int buf)
{
	if (buf < 0 || buf > 200)
		return (true);
	else
	{
		age = buf;
		return (false);
	}
}

bool Human::SetHeight(int buf)
{
	if (buf < 40 || buf > 300)
		return (true);
	else
	{
		height = buf;
		return (false);
	}
}

bool Human::SetWeight(double buf)
{
	buf = round(buf * 10) / 10;
	if (buf < 0 || buf > 650)
		return (true);
	else
	{
		weight = buf;
		return (false);
	}
}

bool Human::SetGender(char buf)
{
	if (buf == 'M' || buf == 'F')
	{
		gender = buf;
		return (false);
	}
	else
		return (true);
}

int Human::GetId()
{
	return (id);
}

int Human::GetAge()
{
	return (age);
}

int Human::GetHeight()
{
	return (height);
}

double Human::GetWeight()
{
	return (weight);
}

char Human::GetGender()
{
	return (gender);
}

bool Human::Init(int bufId, int bufAge, int bufHeight, double bufWeight, char bufGender, Fio bufFio)
{
	Human check;

	if (check.SetId(bufId) || check.SetAge(bufAge) || check.SetHeight(bufHeight) || 
		check.SetWeight(bufWeight) || check.SetGender(bufGender))
		return (true);
	else
	{
		SetId(check.GetId());
		SetAge(check.GetAge());
		SetHeight(check.GetHeight());
		SetWeight(check.GetWeight());
		SetGender(check.GetGender());
		fioField = bufFio;
		return (false);
	}
}

bool Human::Read()
{
	Human check;
	int bufInt;
	double bufDouble;
	char bufChar;

	cout << "Enter id:" << endl;
	cin >> bufInt;	
	if (check.SetId(bufInt))
		return (true);
		
	cout << "Enter age:" << endl;
	cin >> bufInt;
	if (check.SetAge(bufInt))
		return (true);
				
	cout << "Enter height:" << endl;
	cin >> bufInt;
	if (check.SetHeight(bufInt))
		return (true);
			
	cout << "Enter weight:" << endl;
	cin >> bufDouble;	
	if (check.SetWeight(bufDouble))
		return (true);

	cout << "Enter gender:" << endl;
	cin >> bufChar;
	cin.ignore();
	if (check.SetGender(bufChar))
		return(true);

	if (check.fioField.Read())
		return (true);

	Init(check.GetId(), check.GetAge(), check.GetHeight(), 
		check.GetWeight(), check.GetGender(), check.fioField);
	return(false);								
}

void Human::Display()
{
	cout << "id: " << id << endl;
	cout << "age: " << age << endl;
	cout << "height: " << height << endl;
	cout << "weight: " << weight << endl;
	cout.precision(2);
	cout << "gender: " << gender << endl;
	fioField.Display();
}
