#include <conio.h>
#include <iostream>
//#include <string.h>
//#include "student.h"
//#include "teacher.h"
//#include "faculty.h"
#include "Fio.h"
//#include "human.h"

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
	cout << "--------FIO class--------" << endl;
	cout << "------Init method-------" << endl;
	Fio myFio;
	myFio.Init("Popov", "Alexandr", "Dmitrievich");
	myFio.Display();

	printf("\n---Read method---\n");
	if (!myFio.Read())
		myFio.Display();
	else
		printf("error\n");

	printf("\n------Set methods-------\n");
	if (myFio.SetSurname("Ivanov") || myFio.SetName("Ivan") || myFio.SetPatronymic(" Ivanovich "))
		printf("error\n");
	else
		myFio.Display();

	/*
	///human struct
	printf("\n--------human class--------\n");

	//Создание нового объекта из готовых данных
	printf("-------Init method-------\n");
	human me;
	char gender[] = "F";
	
	if(me.Init(1913, 19, 70, 182, gender, my_FIO))
		printf("error\n");
	else
		me.Display();
	
	//Ввод полей объекта из консоли
	printf("\n------Read method------\n");
	if (me.Read())
		printf("error\n");
	else
		me.Display();

	//Ввод полей объекта с помощью методов
	printf("\n------Set methods-------\n");
	if (me.SetId(1999) || me.SetAge(27) || me.SetHeight(180) ||
		me.SetWeight(80.890) || me.SetGender(strcpy(gender, "M")))
		printf("error\n");
	else
		me.Display();



	///student struct
	printf("\n--------student class--------\n");
	char EduProg[] = "Bachelor";
	char Group[] = "PI-03";
	char FacultyName[] = "FoIT";

	//Создание нового объекта из готовых данных
	printf("-------Init method-------\n");
	student my_student;
	if (my_student.Init(3, EduProg, Group, FacultyName, me))
		printf("error\n");
	else 
		my_student.Display();

	//Ввод полей объекта из консоли
	printf("\n------Read method------\n");
	if (my_student.Read())
		printf("error\n");
	else
		my_student.Display();

	//Ввод полей объекта с помощью методов
	printf("\n------Set methods-------\n");
	if (my_student.SetCourse(4) || my_student.SetEduProg(strcpy(EduProg, "Master")) || 
		my_student.SetGroup(strcpy(Group, "CS-91")) ||
		my_student.SetFacultyName(strcpy(FacultyName, "FoIT")))
		printf("error\n");
	else
		my_student.Display();



	///teacher struct
	printf("\n--------teacher class--------\n");
	char Degree[40] = "Candidate of Mathematical Sciences";

	//Создание нового объекта из готовых данных
	printf("-------Init method-------\n");
	teacher my_teacher;
	if (my_teacher.Init(40, Degree, FacultyName, me))
		printf("error\n");
	else
		my_teacher.Display();

	//Ввод полей объекта из консоли
	printf("\n------Read method------\n");
	if (my_teacher.Read())
		printf("error\n");
	else
		my_teacher.Display();

	//Ввод полей объекта с помощью методов
	printf("\n------Set methods-------\n");
	if (my_teacher.SetWorkExp(30) || my_teacher.SetDegree(strcpy(Degree, "Doctor of Mathematical Sciences")) || my_teacher.SetFacultyName(FacultyName))
		printf("error\n");
	else
		my_teacher.Display();



	///faculty struct
	printf("\n------faculty class----------\n");

	//Создание нового объекта из готовых данных
	printf("-------Init method-------\n");
	faculty my_faculty;
	if (my_faculty.Init(FacultyName, 180, 145, 35, 40, 20, 5, 70))
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
		dynamic_array[i].Init(FacultyName, i, i, i, i, i, i, i);
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
		array_of_dynamic[i]->Init(FacultyName, i, i, i, i, i, i, i);
		(*array_of_dynamic[i]).Display(); //(*smth). взаимозаменяемо с smth->
		printf("******************\n");
		delete array_of_dynamic[i];
	}
	*/
	//Конец демонстрационного варианта
	printf("\nPress any key to exit.\n");
	_getch();
}
