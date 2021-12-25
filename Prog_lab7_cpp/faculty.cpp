#include "Faculty.h"
#include <iostream>


bool Faculty::SetFacultyName(string bufString)
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

bool Faculty::SetQuantityOfStudents(int buf)
{
	if (buf < 0 || buf > 1000)
		return (true);
	else
	{
		quantityOfStudents = buf;
		return (false);
	}
}

bool Faculty::SetQuantityOfBachelors(int buf)
{
	if (buf < 0 || buf > 1000)
		return (true);
	else
	{
		quantityOfBachelors = buf;
		return (false);
	}
}

bool Faculty::SetQuantityOfMasters(int buf)
{
	if (buf < 0 || buf > 1000)
		return (true);
	else
	{
		quantityOfMasters = buf;
		return (false);
	}
}

bool Faculty::SetQuantityOfTeachers(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		quantityOfTeachers = buf;
		return (false);
	}
}

bool Faculty::SetQuantityOfCandidates(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		quantityOfCandidates = buf;
		return (false);
	}
}

bool Faculty::SetQuantityOfDoctors(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		quantityOfDoctors = buf;
		return (false);
	}
}

bool Faculty::SetQuantityOfDisciplines(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		quantityOfDisciplines = buf;
		return (false);
	}
}

bool Faculty::SetStudentsInfo(int allQuantity, int bachelorsQuantity, int mastersQuantity)
{
	if (allQuantity < 0 || allQuantity > 1000 || bachelorsQuantity < 0 || bachelorsQuantity > 1000 || mastersQuantity < 0 || mastersQuantity > 1000)
		return (true);
	else
	{
		quantityOfStudents = allQuantity;
		quantityOfBachelors = bachelorsQuantity;
		quantityOfMasters = mastersQuantity;
		return (false);
	}
}

bool Faculty::SetTeachersInfo(int allQuantity, int candidatesQuantity, int doctorsQuantity)
{
	if (allQuantity < 0 || allQuantity > 100 || candidatesQuantity < 0 || candidatesQuantity > 100 || doctorsQuantity < 0 || doctorsQuantity > 100)
		return (true);
	else
	{
		quantityOfTeachers = allQuantity;
		quantityOfCandidates = candidatesQuantity;
		quantityOfDoctors = doctorsQuantity;
		return (false);
	}
}



string Faculty::GetFacultyName()
{
	return (facultyName);
}

int Faculty::GetQuantityOfStudents()
{
	return (quantityOfStudents);
}

int Faculty::GetQuantityOfBachelors()
{
	return (quantityOfBachelors);
}

int Faculty::GetQuantityOfMasters()
{
	return (quantityOfMasters);
}

int Faculty::GetQuantityOfTeachers()
{
	return (quantityOfTeachers);
}

int Faculty::GetQuantityOfCandidates()
{
	return (quantityOfCandidates);
}

int Faculty::GetQuantityOfDoctors()
{
	return (quantityOfDoctors);
}

int Faculty::GetQuantityOfDisciplines()
{
	return (quantityOfDisciplines);
}

double Faculty::GetProcentOfMasters()
{
	return(((double)quantityOfMasters) / ((double)quantityOfStudents) * 100);
}

double Faculty::GetProcentOfDoctors()
{
	return(((double)quantityOfDoctors) / ((double)quantityOfTeachers) * 100);
}

double Faculty::GetStudToTeachRatio()
{
	return(((double)quantityOfStudents) / ((double)quantityOfTeachers));
}

Faculty Faculty::GetWithMoreCandidates(Faculty buf)
{
	if ((*this).GetQuantityOfCandidates() >= buf.GetQuantityOfCandidates())
		return (*this);
	else
		return (buf);
}

void Faculty::IsHavingEnoughCandidates(bool *result)
{
	if (quantityOfCandidates > 30)
		*result = true;
	else
		*result = false;
}

void Faculty::IsHavingEnoughCandidates(bool &result)
{
	if (quantityOfCandidates > 30)
		result = true;
	else
		result = false;
}

bool Faculty::Init(string bufFacultyName, int studentsQuantity, int bachelorsQuantity, int mastersQuantity, int teachersQuantity, int candidatesQuantity, int doctorsQuanity, int discpilinesQuantity)
{
	Faculty check;
 
	if (check.SetFacultyName(bufFacultyName) || check.SetQuantityOfStudents(studentsQuantity) ||
		check.SetQuantityOfBachelors(bachelorsQuantity) || check.SetQuantityOfMasters(mastersQuantity) ||
		check.SetQuantityOfTeachers(teachersQuantity) || check.SetQuantityOfCandidates(candidatesQuantity) ||
		check.SetQuantityOfDoctors(doctorsQuanity) || check.SetQuantityOfDisciplines(discpilinesQuantity))
		return (true);
	else
	{
		SetFacultyName(bufFacultyName);
		SetQuantityOfStudents(studentsQuantity);
		SetQuantityOfBachelors(bachelorsQuantity);
		SetQuantityOfMasters(mastersQuantity);
		SetQuantityOfTeachers(teachersQuantity);
		SetQuantityOfCandidates(candidatesQuantity);
		SetQuantityOfDoctors(doctorsQuanity);
		SetQuantityOfDisciplines(discpilinesQuantity);
		return (false);
	}
}

bool Faculty::Read()
{
	Faculty check;
	string bufString;
	int bufInt;

	cout << "Enter faculty name:\n";
	getline(cin, bufString);
	if (check.SetFacultyName(bufString))
		return (true);
	
	cout << "Enter quantity of students:\n";
	cin >> bufInt;
	if (check.SetQuantityOfStudents(bufInt))
		return (true);
			
	cout << "Enter quantity of bachelors:\n";
	cin >> bufInt;
	if (check.SetQuantityOfBachelors(bufInt))
		return (true);
					
	cout << "Enter quantity of masters:\n";
	cin >> bufInt;
	if (check.SetQuantityOfMasters(bufInt))
		return (true);
								
	cout << "Enter quantity of teachers:\n";
	cin >> bufInt;
	if (check.SetQuantityOfTeachers(bufInt))
		return (true);
									
	cout << "Enter quantity of candidates:\n";
	cin >> bufInt;
	if (check.SetQuantityOfCandidates(bufInt))
		return (true);
			
	cout << "Enter quantity of doctors:\n";
	cin >> bufInt;
	if (check.SetQuantityOfDoctors(bufInt))
		return (true);
													
	cout << "Enter quantity of disciplines:\n";
	cin >> bufInt;
	if (check.SetQuantityOfDisciplines(bufInt))
		return (true);
															
	Init(check.GetFacultyName(), check.GetQuantityOfStudents(), 
		check.GetQuantityOfBachelors(), check.GetQuantityOfMasters(), 
		check.GetQuantityOfTeachers(), check.GetQuantityOfCandidates(),
		check.GetQuantityOfDoctors(), check.GetQuantityOfDisciplines());
	return (false);												
}

void Faculty::Display()
{
	cout << "faculty name: " << facultyName << endl;
	cout << "quantity of students:" << quantityOfStudents << endl;
	cout << "quantity of bachelors: " << quantityOfBachelors << endl;
	cout << "quantity of masters: " << quantityOfMasters << endl;

	cout << "quantity of teachers: " << quantityOfTeachers << endl;
	cout << "quantity of candidates: " << quantityOfCandidates << endl;
	cout << "quantity of doctors: " << quantityOfDoctors << endl;

	cout << "quantity of disciplines: " << quantityOfDisciplines << endl;
}
