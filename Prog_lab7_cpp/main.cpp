#include <conio.h>
#include <iostream>
//#include <string.h>
//#include "student.h"
//#include "teacher.h"
//#include "faculty.h"
#include "Fio.h"
#include "Human.h"

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


	/*
	///student struct
	printf("\n--------student class--------\n");
	char EduProg[] = "Bachelor";
	char Group[] = "PI-03";
	char FacultyName[] = "FoIT";

	//�������� ������ ������� �� ������� ������
	printf("-------Init method-------\n");
	student my_student;
	if (my_student.Init(3, EduProg, Group, FacultyName, myHuman))
		printf("error\n");
	else 
		my_student.Display();

	//���� ����� ������� �� �������
	printf("\n------Read method------\n");
	if (my_student.Read())
		printf("error\n");
	else
		my_student.Display();

	//���� ����� ������� � ������� �������
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

	//�������� ������ ������� �� ������� ������
	printf("-------Init method-------\n");
	teacher my_teacher;
	if (my_teacher.Init(40, Degree, FacultyName, myHuman))
		printf("error\n");
	else
		my_teacher.Display();

	//���� ����� ������� �� �������
	printf("\n------Read method------\n");
	if (my_teacher.Read())
		printf("error\n");
	else
		my_teacher.Display();

	//���� ����� ������� � ������� �������
	printf("\n------Set methods-------\n");
	if (my_teacher.SetWorkExp(30) || my_teacher.SetDegree(strcpy(Degree, "Doctor of Mathematical Sciences")) || my_teacher.SetFacultyName(FacultyName))
		printf("error\n");
	else
		my_teacher.Display();



	///faculty struct
	printf("\n------faculty class----------\n");

	//�������� ������ ������� �� ������� ������
	printf("-------Init method-------\n");
	faculty my_faculty;
	if (my_faculty.Init(FacultyName, 180, 145, 35, 40, 20, 5, 70))
		printf("error\n");
	else
		my_faculty.Display();

	//���� ����� ������� �� �������
	printf("\n------Read method------\n");
	if (my_faculty.Read())
		printf("error\n");
	else
		my_faculty.Display();

	//���� ����� ������� � ������� �������
	printf("\n------Shortcut-Set methods-------\n");
	my_faculty.SetStudentsInfo(300, 270, 30);
	my_faculty.SetTeachersInfo(40, 33, 7);
	my_faculty.Display();

	//����� ������ ����������� ������� ������ � �������
	printf("\n----processing by functions----\n");
	printf("Procent of masters on faculty: %0.2lf\n", my_faculty.ProcentOfMasters());
	printf("Procent of doctors on faculty: %0.2lf\n", my_faculty.ProcentOfDoctors());
	printf("Students to teachers quantity: %0.2lf\n", my_faculty.ProcOfStudToTeach());



	///������������ ������ � �������
	printf("\n------dynamic memmory demo------\n");
	printf("----dynamic array of objects----\n");

	int count; //���-�� �������� ������������� �������
	printf("Enter the number of objects, that you want to create:\n");
	scanf("%d", &count);

	//dynamic_array[i] - ������ ������ 
	faculty* dynamic_array = new faculty[count];//������������ ������ �������� ������ faculty.
	for (int i = 0; i < count; i++) 
	{
		dynamic_array[i].Init(FacultyName, i, i, i, i, i, i, i);
		dynamic_array[i].Display();
		printf("******************\n");
	}
	delete[] dynamic_array;
	
	printf("\n----array of 5 dynamic objects----\n\n");
	//�������� 5 ���������� �� ������� ������ faculty
	//���������� ���� ���������� �� ����������!!!
	//array_of_dynamic[i] - ��������� �� ������
	faculty* array_of_dynamic[5];
	for (int i = 0; i < 5; i++) 
	{
		//���������� ���������� ������� �� ����������
		array_of_dynamic[i] = new faculty;
		array_of_dynamic[i]->Init(FacultyName, i, i, i, i, i, i, i);
		(*array_of_dynamic[i]).Display(); //(*smth). ��������������� � smth->
		printf("******************\n");
		delete array_of_dynamic[i];
	}
	*/
	//����� ����������������� ��������
	printf("\nPress any key to exit.\n");
	_getch();
}
