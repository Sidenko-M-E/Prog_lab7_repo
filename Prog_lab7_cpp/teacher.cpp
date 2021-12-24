#include "Teacher.h"
#include <iostream>


bool Teacher::SetWorkExp(int buf)
{
	if (buf < 0 || buf > 60)
		return (true);
	else
	{
		workExp = buf;
		return (false);
	}
}

bool Teacher::SetDegree(string bufString)
{
	if (bufString.empty())
		return (true);

	char invalidSymbols[] = "!@#$%^&*()_+1234567890-=\"¹;:?*,./'][{}<>~`";
	for (char symb : invalidSymbols)
	{
		if (bufString.find(symb) != (-1))
			return (true);
	}

	degree = bufString;
	return (false);
}

bool Teacher::SetFacultyName(string bufString)
{
	if (bufString.empty())
		return (true);

	char invalidSymbols[] = "!@#$%^&*()_+1234567890-=\"¹;:?*,./'][{}<>~` ";
	for (char symb : invalidSymbols)
	{
		if (bufString.find(symb) != (-1))
			return (true);
	}

	facultyName = bufString;
	return (false);
}

int Teacher::GetWorkExp()
{
	return (workExp);
}

string Teacher::GetDegree()
{
	return (degree);
}

string Teacher::GetFacultyName()
{
	return (facultyName);
}

Teacher Teacher::operator+(int operatorWorkExp)
{
	Teacher resultObject;
	resultObject.workExp = this->workExp + operatorWorkExp;
	resultObject.degree = this->degree;
	resultObject.facultyName = this->facultyName;
	resultObject.humanField = this->humanField;
	return (resultObject);
}

int operator+(int operatorWorkExp, Teacher operatorTeacher)
{
	return (operatorTeacher.workExp + operatorWorkExp);
}

Teacher& Teacher::operator++()//prefix
{
	this->workExp++;
	return *this;
}

Teacher Teacher::operator++(int unused)//postfix
{
	Teacher resultObject = *this;
	++*this;
	return resultObject;
}

bool Teacher::Init(int bufWorkExp, string bufDegree, string bufFacultyName, Human bufHuman)
{
	Teacher check;

	if (check.SetWorkExp(bufWorkExp) || check.SetDegree(bufDegree) || check.SetFacultyName(bufFacultyName))
		return (true);
	else
	{
		SetWorkExp(bufWorkExp);
		SetDegree(bufDegree);
		SetFacultyName(bufFacultyName);
		humanField = bufHuman;
		return (false);
	}
}

bool Teacher::Read()
{
	Teacher check;
	int bufInt;
	string bufString;

	cout << "Enter working experience:\n";
	cin >> bufInt;
	cin.ignore();
	if (check.SetWorkExp(bufInt))
		return (true);
				
	cout << "Enter scientific degree:\n";
	getline(cin, bufString);
	if (check.SetDegree(bufString))
		return (true);
			
	cout << "Enter faculty name:\n";
	getline(cin, bufString);
	if (check.SetFacultyName(bufString))
		return (true);
	
	if (check.humanField.Read())
		return (true);

	Init(check.GetWorkExp(), check.GetDegree(), 
		check.GetFacultyName(), check.humanField);
	return(false);
}

void Teacher::Display()
{
	cout << "working experience: " << workExp << " years" << endl;
	cout << "scientific degree: " << degree << endl;
	cout << "faculty name: " << facultyName << endl;
	humanField.Display();
}

