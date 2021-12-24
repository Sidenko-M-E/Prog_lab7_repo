#pragma once
#include "Human.h"


class Teacher {
private:
	int workExp;
	string degree;
	string facultyName;

public:
	Human humanField;

	bool SetWorkExp(int buf);
	bool SetDegree(string bufString);
	bool SetFacultyName(string bufString);

	int GetWorkExp();
	string GetDegree();
	string GetFacultyName();

	Teacher operator+ (int operatorWorkExp);//Teacher+int=Teacher
	friend int operator+ (int operatorWorkExp, Teacher operatorTeacher); //int+Teacher=int
	Teacher& operator++();//prefix
	Teacher operator++(int unused);//postfix

	bool Init(int bufWorkExp, string bufDegree, string bufFacultyName, Human bufHuman);
	bool Read();
	void Display();
};
