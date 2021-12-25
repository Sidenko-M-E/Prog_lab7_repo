#include <conio.h>
#include <iostream>
#include "Fio.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Faculty.h"

//test
	/*
	FIO myFio;
	myFio.Init("Sidenko", "Matvey", "Evgenievich");
	myFio.Display();

	FIO demoFio;
	demoFio.Init("Petrov", "Oleg", "Victorovich");
	demoFio.Display();

	myFio = demoFio;
	myFio.Display();

	demoFio.Init("fff", "ggg", "ddd");
	demoFio.Display();
	myFio.Display();
	*/

int main()
{

	/*
	cout << "--------Fio class--------" << endl;
	cout << "------Init method-------" << endl;
	Fio myFio;
	myFio.Init("Popov", "Alexandr", "Dmitrievich");
	myFio.Display();
	*/
	/*
	cout << endl << "---Read method---" << endl;
	if (!myFio.Read())
		myFio.Display();
	else
		cout << "error" << endl;

	cout << endl << "------Set methods-------" << endl;
	if (myFio.SetSurname("Ivanov") || myFio.SetName("Ivan") || myFio.SetPatronymic("Ivanovich"))
		cout << "error" << endl;
	else
		myFio.Display();
	*/

	/*
	cout << endl << "--------Human class--------" << endl;
	cout << "-------Init method-------" << endl;
	Human myHuman;
	if(myHuman.Init(1913, 19, 182, 70, 'F', myFio))
		cout << "error" << endl;
	else
		myHuman.Display();
	*/
	/*
	cout << "\n------Read method------\n";
	if (myHuman.Read())
		cout << "error\n";
	else
		myHuman.Display();

	cout << "\n------Set methods-------\n";
	if (myHuman.SetId(1999) || myHuman.SetAge(27) || myHuman.SetHeight(180) ||
		myHuman.SetWeight(80.890) || myHuman.SetGender('M'))
		cout << "error\n";
	else
		myHuman.Display();
	*/

	/*
	cout << "\n--------Student class--------\n";
	cout << "-------Init method-------\n";
	Student myStudent;
	if (myStudent.Init(3, "Bachelor", "PI-03", "FoIT", myHuman))
		cout << "error\n";
	else 
		myStudent.Display();

	cout << "\n------Read method------\n";
	if (myStudent.Read())
		cout << "error\n";
	else
		myStudent.Display();

	cout << "\n------Set methods-------\n";
	if (myStudent.SetCourse(4) || myStudent.SetEduProg("Master") || 
		myStudent.SetGroup("CS-91") ||
		myStudent.SetFacultyName("FoIT"))
		cout << "error\n";
	else
		myStudent.Display();
	*/

	/*
	cout << "\n--------Teacher class--------\n";
	cout << "-------Init method-------\n";
	Teacher myTeacher;
	if (myTeacher.Init(40, "Candidate of Mathematical Sciences", 
		"FoMS", myHuman))
		cout << "error\n";
	else
		myTeacher.Display();

	cout << "\n------Read method------\n";
	if (myTeacher.Read())
		cout << "error\n";
	else
		myTeacher.Display();

	cout << "\n------Set methods-------\n";
	if (myTeacher.SetWorkExp(30) || myTeacher.SetDegree("Doctor of Mathematical Sciences") || myTeacher.SetFacultyName("FoMS"))
		cout << "error\n";
	else
		myTeacher.Display();
	*/

	/*
	cout << "\n----operator overloading demo----\n";
	Teacher demoTeacher;
	demoTeacher.Init(40, "Candidate of Mathematical Sciences",
		"FoMS", myHuman);
	cout << "demoTeacher.WorkExp = " << demoTeacher.GetWorkExp() << endl;

	demoTeacher = demoTeacher + 3;
	cout << "\ndemoTeacher + 3 = new object of Teacher class:\n";
	demoTeacher.Display();

	cout << "\n4 + demoTeacher = " << 4 + demoTeacher << " of int\n";

	cout << "\ndemoTeacher++\n";
	demoTeacher++;
	demoTeacher.Display();

	cout << "\n++demoTeacher:\n";
	++demoTeacher;
	demoTeacher.Display();
	*/

	cout << "\n------Faculty class----------\n";
	cout << "-------Init method-------\n";
	Faculty myFaculty;
	if (myFaculty.Init("FoHS", 180, 145, 35, 40, 20, 5, 70));
	//	cout << "error\n";
	//else
	//	myFaculty.Display();
	
	/*
	cout << "\n------Read method------\n";
	if (myFaculty.Read())
		cout << "error\n";
	else
		myFaculty.Display();

	cout << "\n------Shortcut-Set methods-------\n";
	myFaculty.SetStudentsInfo(300, 270, 30);
	myFaculty.SetTeachersInfo(40, 33, 7);
	myFaculty.Display();
	*/
	/*
	cout << "\n----processing by functions----\n";
	cout.precision(2);
	cout << "Procent of masters on faculty: " << myFaculty.GetProcentOfMasters() << endl;
	cout << "Procent of doctors on faculty: " << myFaculty.GetProcentOfDoctors() << endl;
	cout << "Students to teachers ratio: " << myFaculty.GetStudToTeachRatio() << endl;
	*/
	/*
	cout << "\nLet's compare two faculties to find the one...\n";
	cout << "...that have the largest number of candidates on it.\n";
	Faculty demoFaculty;
	demoFaculty.Init("FoMS", 230, 175, 15, 30, 45, 15, 80);
	cout << "First faculty:\n";
	myFaculty.Display();
	cout << "Second faculty:\n";
	demoFaculty.Display();
	cout << "And result is...\n";
	(myFaculty.GetWithMoreCandidates(demoFaculty)).Display();
	*/
	cout << "\nLets check the faculties to find the one...\n";
	cout << "...that have enough candidates on it.\n";
	bool result;

	cout << "\nFirst faculty:\n";
	myFaculty.Display();
	cout << "\nLets check the first faculty:\n";
	myFaculty.IsHavingEnoughCandidates(&result);
	if (result)
		cout << "First faculty have enough candidates.\n";
	else
		cout << "First faculty have not enough candidates.\n";

	cout << "\nSecond faculty:\n";
	Faculty demoFaculty;
	demoFaculty.Init("FoMS", 230, 175, 15, 30, 45, 15, 80);
	demoFaculty.Display();
	cout << "\nLets check the second faculty\n";
	demoFaculty.IsHavingEnoughCandidates(result);
	if (result)
		cout << "Second faculty have enough candidates.\n";
	else
		cout << "Second faculty have not enough candidates.\n";
		
	/*
	cout << "\n------dynamic memmory demo------\n";
	cout << "----dynamic array of objects----\n";
	int count;
	printf("Enter the number of objects, that you want to create:\n");
	cin >> count;

	//dynamic_array[i] - объект класса 
	Faculty* dynamicArray = new Faculty[count];//динамический массив объектов класса faculty.
	for (int i = 0; i < count; i++) 
	{
		dynamicArray[i].Init("SMTH", i, i, i, i, i, i, i);
		dynamicArray[i].Display();
		cout << "******************\n";
	}
	delete[] dynamicArray;
	
	cout << "\n----array of 5 dynamic objects----\n\n";
	//создание 5 указателей на объекты класса faculty
	//содержимое этих указателей не определено!!!
	//array_of_dynamic[i] - указатель на объект
	Faculty* arrayOfDynamic[5];
	for (int i = 0; i < 5; i++) 
	{
		//определяем содержимое каждого из указателей
		arrayOfDynamic[i] = new Faculty;
		arrayOfDynamic[i]->Init("SMTH", i, i, i, i, i, i, i);
		(*arrayOfDynamic[i]).Display(); //(*smth). взаимозаменяемо с smth->
		cout << "******************\n";
		delete arrayOfDynamic[i];
	}
	*/
	//Конец демонстрационного варианта
	cout << "\nPress any key to exit.\n";
	_getch();
}
