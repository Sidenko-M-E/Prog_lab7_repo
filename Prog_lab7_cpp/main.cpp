#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "student.h"
#include "teacher.h"
#include "faculty.h"
#include "FIO.h"
#include "human.h"


int main()
{
	///FIO struct
	printf("--------FIO class--------\n");
	char Familia[30] = "Sidenko";
	char Imya[30] = "Matvey";
	char Otchestvo[30] = "Evgenievich";

	//�������� ������ ������� �� ������� ������
	printf("------Init method-------\n");
	FIO my_FIO;
	
	if(my_FIO.Init(Familia, Imya, Otchestvo))
		printf("error\n");
	else
		my_FIO.Display();

	//���� ����� ������� �� �������
	printf("\n---Read method---\n");
	if (!my_FIO.Read())
		my_FIO.Display();
	else
		printf("error\n");

	//���� ����� ������� � ������� �������
	printf("\n------Set methods-------\n");
	if ((my_FIO.SetSurName(strcpy(Familia, " Ivanov ")))||(my_FIO.SetName(strcpy(Imya, " Ivan ")))||(my_FIO.SetPatronymic(strcpy(Otchestvo, " Ivanovich "))))
		printf("error\n");
	else
		my_FIO.Display();



	///human struct
	printf("\n--------human class--------\n");

	//�������� ������ ������� �� ������� ������
	printf("-------Init method-------\n");
	human me;
	char gender[] = "F";
	
	if(me.Init(1913, 19, 70, 182, gender, my_FIO))
		printf("error\n");
	else
		me.Display();
	
	//���� ����� ������� �� �������
	printf("\n------Read method------\n");
	if (me.Read())
		printf("error\n");
	else
		me.Display();

	//���� ����� ������� � ������� �������
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

	//�������� ������ ������� �� ������� ������
	printf("-------Init method-------\n");
	student my_student;
	if (my_student.Init(3, EduProg, Group, FacultyName, me))
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
	if (my_teacher.Init(40, Degree, FacultyName, me))
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
	
	//����� ����������������� ��������
	printf("\nPress any key to exit.\n");
	_getch();
}
