#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "student.h"

//Метод установки курса обучения
bool student::SetCourse(int buf)
{
	if (buf < 0 || buf > 6)
		return (true);
	else
	{
		course = buf;
		return (false);
	}
}

//Метод установки учебной программы
bool student::SetEduProg(char buf_string[])
{
	//обрезка входной строки
	if (strlen(buf_string) > (FIO_fields_size / 3 * 2))
		buf_string[(FIO_fields_size / 3 * 2) - 1] = '\0';

	//проверка на ввод пустой строки
	if (strlen(buf_string) == 0)
		return (true);

	//определение массива недопустимых символов
	char invalid_symbols[] = "!@#$%^&*()_+1234567890-=\"№;:?*,./'][{}<>~` ";
	int invalid_symbols_lenght = 43;

	//посимвольное сравнение входной строки и массива недопустимых символов
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//копирование входной строки в поле объекта,
	//при успешном прохождении проверки
	strcpy(EduProg, buf_string);
	return (false);
}

//Метод установки названия группы
bool student::SetGroup(char buf_string[])
{
	//обрезка входной строки
	if (strlen(buf_string) > (FIO_fields_size / 3))
		buf_string[(FIO_fields_size / 3) - 1] = '\0';

	//проверка на ввод пустой строки
	if (strlen(buf_string) == 0)
		return (true);

	//определение массива недопустимых символов
	char invalid_symbols[] = "!@#$%^&*()_+=\"№;:?*,./'][{}<>~` ";
	int invalid_symbols_lenght = 32;

	//посимвольное сравнение входной строки и массива недопустимых символов
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//копирование входной строки в поле объекта,
	//при успешном прохождении проверки
	strcpy(Group, buf_string);
	return (false);
}

//Метод установки названия факультета
bool student::SetFacultyName(char buf_string[])
{
	//обрезка входной строки
	if (strlen(buf_string) > FIO_fields_size)
		buf_string[FIO_fields_size - 1] = '\0';

	//проверка на ввод пустой строки
	if (strlen(buf_string) == 0)
		return (true);

	//определение массива недопустимых символов
	char invalid_symbols[] = "!@#$%^&*()_+1234567890-=\"№;:?*,./'][{}<>~` ";
	int invalid_symbols_lenght = 43;

	//посимвольное сравнение входной строки и массива недопустимых символов
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//копирование входной строки в поле объекта,
	//при успешном прохождении проверки
	strcpy(FacultyName, buf_string);
	return (false);
}

//Метод извлечения курса обучения
int student::GetCourse()
{
	int buf = course;
	return (buf);
}

//Метод извлечения учебной программы
char* student::GetEduProg()
{
	char* buf_string = (char*)calloc(FIO_fields_size / 3 * 2, sizeof(char));
	strcpy(buf_string, EduProg);
	return (buf_string);
}

//Метод извлечения названия группы
char* student::GetGroup()
{
	char* buf_string = (char*)calloc(FIO_fields_size / 3, sizeof(char));
	strcpy(buf_string, Group);
	return (buf_string);
}

//Метод извлечения названия факультета
char* student::GetFacultyName()
{
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, FacultyName);
	return (buf_string);
}

//Метод  инициализации объекта класса
bool student::Init(int buf_course, char buf_EduProg[], char buf_Group[], char buf_FacultyName[], human buf_human)
{
	//создаём объект класса student для проверки формата входных данных
	student check;

	//проверка на формат ввода human??????????
	if (check.SetCourse(buf_course) || check.SetEduProg(buf_EduProg) || check.SetGroup(buf_Group) ||
		check.SetFacultyName(buf_FacultyName))
		return (true);
	else
	{
		SetCourse(buf_course);
		SetEduProg(buf_EduProg);
		SetGroup(buf_Group);
		SetFacultyName(buf_FacultyName);
		thehuman = buf_human;
		return (false);
	}
}

//Метод ввода полей объекта класса из консоли
bool student::Read()
{
	//создаём объект класса student для проверки формата входных данных
	student check;

	//буферный переменная типа int 
	//для проверки формата входных данных 
	int buf_int;

	//проверка на формат входных данных
	printf("Enter course:\n");
	if (scanf("%d", &buf_int) != 1)
		return (true);
	else
	{
		//попытка записи в поле объекта
		if (check.SetCourse(buf_int))
			return (true);
		else
		{
			//создаём буферную строку для проверки формата входных данных
			char buf_string[FIO_fields_size];
			rewind(stdin);
			printf("Enter education programm:\n");
			fgets(buf_string, FIO_fields_size / 3 * 2, stdin);
			//если строка короче 20, то заменить "перенос на новую строку" "концом строки"
			if (buf_string[strlen(buf_string) - 1] == '\n')
				buf_string[strlen(buf_string) - 1] = '\0';
			//если строка длиннее 20, то очистить входной поток
			else rewind(stdin);

			//попытка записи в поле объекта
			if (check.SetEduProg(buf_string))
				return (true);
			else
			{
				printf("Enter group:\n");
				fgets(buf_string, FIO_fields_size / 3, stdin);
				//если строка короче 10, то заменить "перенос на новую строку" "концом строки"
				if (buf_string[strlen(buf_string) - 1] == '\n')
					buf_string[strlen(buf_string) - 1] = '\0';
				//если строка длиннее 10, то очистить входной поток
				else rewind(stdin);

				//попытка записи в поле объекта
				if (check.SetGroup(buf_string))
					return (true);
				else
				{
					printf("Enter faculty name:\n");
					fgets(buf_string, FIO_fields_size, stdin);
					//если строка короче 10, то заменить "перенос на новую строку" "концом строки"
					if (buf_string[strlen(buf_string) - 1] == '\n')
						buf_string[strlen(buf_string) - 1] = '\0';
					//если строка длиннее 10, то очистить входной поток
					else rewind(stdin);

					//попытка записи в поле объекта
					if (check.SetFacultyName(buf_string))
						return (true);
					else
					{
						//попытка записи в объект
						if (check.thehuman.Read())
							return (true);

						//когда все проверки пройдены,
						//можно перенести данные в главный объект
						else
						{
							SetCourse(check.GetCourse());
							SetEduProg(check.GetEduProg());
							SetGroup(check.GetGroup());
							SetFacultyName(check.GetFacultyName());
							thehuman = check.thehuman;
							return(false);
						}
					}
				}
			}
		}
	}
}

//Метод вывода содержимого объекта класса в консоль
void student::Display()
{
	printf("course: %d\n", course);
	printf("direction of preparation: %s\n", EduProg);
	printf("group: %s\n", Group);
	printf("faculty name: %s\n", FacultyName);
	thehuman.Display();
}
