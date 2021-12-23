#pragma once
#include "Human.h"


class Student {
private:
	int course;
	string eduProg;
	string group;
	string facultyName;

public:
	Human humanField;

	bool SetCourse(int buf);
	bool SetEduProg(string bufString);
	bool SetGroup(string bufString);
	bool SetFacultyName(string bufString);

	int GetCourse();
	string GetEduProg();
	string GetGroup();
	string GetFacultyName();

	bool Init(int bufCourse, string bufEduProg, string bufGroup, string bufFacultyName, Human bufHuman);
	bool Read();
	void Display();
};
