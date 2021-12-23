#include <conio.h>
#include <iostream>
//#include <string.h>
//#include "faculty.h"
#include "Fio.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"

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
	cout << "--------Fio class--------" << endl;
	cout << "------Init method-------" << endl;
	Fio myFio;
	myFio.Init("Popov", "Alexandr", "Dmitrievich");
	myFio.Display();

	cout << endl << "---Read method---" << endl;
	if (!myFio.Read())
		myFio.Display();
	else
		cout << "error" << endl;

	cout << endl << "------Set methods-------" << endl;
	if (myFio.SetSurname("Ivanov") || myFio.SetName("Ivan") || myFio.SetPatronymic(" Ivanovich "))
		cout << "error" << endl;
	else
		myFio.Display();



	cout << endl << "--------Human class--------" << endl;
	cout << endl << "-------Init method-------" << endl;
	Human myHuman;
	if(myHuman.Init(1913, 19, 70, 182, 'F', myFio))
		cout << "error" << endl;
	else
		myHuman.Display();
	
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



	cout << "\n--------Teacher class--------\n";
	cout << "-------Init method-------\n";
	Teacher myTeacher;
	if (myTeacher.Init(40, "Candidate of Mathematical Sciences", 
		"CS-091", myHuman))
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


	/*
	///faculty struct
	cout << "\n------faculty class----------\n");

	//Создание нового объекта из готовых данных
	printf("-------Init method-------\n");
	faculty my_faculty;
	if (my_faculty.Init(facultyName, 180, 145, 35, 40, 20, 5, 70))
		printf("error\n");
	else
		my_faculty.Display();

	//Ввод полей объекта из консоли
	printf("\n------Read method------\n");
	if (my_faculty.Read())
		printf("error\n");
	else
		my_faculty.Display();

	//Ввод полей объекта с помощью методов
	printf("\n------Shortcut-Set methods-------\n");
	my_faculty.SetStudentsInfo(300, 270, 30);
	my_faculty.SetTeachersInfo(40, 33, 7);
	my_faculty.Display();

	//Метод вывода содержимого объекта класса в консоль
	printf("\n----processing by functions----\n");
	printf("Procent of masters on faculty: %0.2lf\n", my_faculty.ProcentOfMasters());
	printf("Procent of doctors on faculty: %0.2lf\n", my_faculty.ProcentOfDoctors());
	printf("Students to teachers quantity: %0.2lf\n", my_faculty.ProcOfStudToTeach());



	///Демонстрация работы с памятью
	printf("\n------dynamic memmory demo------\n");
	printf("----dynamic array of objects----\n");

	int count; //кол-во объектов динамического массива
	printf("Enter the number of objects, that you want to create:\n");
	scanf("%d", &count);

	//dynamic_array[i] - объект класса 
	faculty* dynamic_array = new faculty[count];//динамический массив объектов класса faculty.
	for (int i = 0; i < count; i++) 
	{
		dynamic_array[i].Init(facultyName, i, i, i, i, i, i, i);
		dynamic_array[i].Display();
		printf("******************\n");
	}
	delete[] dynamic_array;
	
	printf("\n----array of 5 dynamic objects----\n\n");
	//создание 5 указателей на объекты класса faculty
	//содержимое этих указателей не определено!!!
	//array_of_dynamic[i] - указатель на объект
	faculty* array_of_dynamic[5];
	for (int i = 0; i < 5; i++) 
	{
		//определяем содержимое каждого из указателей
		array_of_dynamic[i] = new faculty;
		array_of_dynamic[i]->Init(facultyName, i, i, i, i, i, i, i);
		(*array_of_dynamic[i]).Display(); //(*smth). взаимозаменяемо с smth->
		printf("******************\n");
		delete array_of_dynamic[i];
	}
	*/
	//Конец демонстрационного варианта
	printf("\nPress any key to exit.\n");
	_getch();
}
