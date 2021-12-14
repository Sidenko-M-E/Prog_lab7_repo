#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "teacher.h"

//Метод установки рабочего стажа
bool teacher::SetWorkExp(int buf)
{
	if (buf < 0 || buf > 60)
		return (true);
	else
	{
		WorkExp = buf;
		return (false);
	}
}

//Метод установки ученой степени
bool teacher::SetDegree(char buf_string[])
{
	//обрезка входной строки
	if (strlen(buf_string) > 40)
		buf_string[40 - 1] = '\0';

	//проверка на ввод пустой строки
	if (strlen(buf_string) == 0)
		return (true);

	//определение массива недопустимых символов
	char invalid_symbols[] = "!@#$%^&*()_+1234567890-=\"№;:?*,./'][{}<>~`";
	int invalid_symbols_lenght = 42;

	//посимвольное сравнение входной строки и массива недопустимых символов
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//копирование входной строки в поле объекта,
	//при успешном прохождении проверки
	strcpy(Degree, buf_string);
	return (false);
}

//Метод установки названия факультета
bool teacher::SetFacultyName(char buf_string[])
{
	//обрезка входной строки
	if (strlen(buf_string) > 30)
		buf_string[30 - 1] = '\0';

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

//Метод извлечения рабочего стажа
int teacher::GetWorkExp()
{
	int buf = WorkExp;
	return (buf);
}

//Метод извлечения ученой степени
char* teacher::GetDegree()
{
	char* buf_string = (char*)calloc(40, sizeof(char));
	strcpy(buf_string, Degree);
	return (buf_string);
}

//Метод извлечения названия факультета
char* teacher::GetFacultyName()
{
	char* buf_string = (char*)calloc(30, sizeof(char));
	strcpy(buf_string, FacultyName);
	return (buf_string);
}

//Метод  инициализации объекта класса
bool teacher::Init(int buf_WorkExp, char buf_Degree[], char buf_FacultyName[], human buf_human)
{
	//создаём объект класса human для проверки формата входных данных
	teacher check;

	//проверка на формат ввода human??????????
	if (check.SetWorkExp(buf_WorkExp) || check.SetDegree(buf_Degree) || check.SetFacultyName(buf_FacultyName))
		return (true);
	else
	{
		SetWorkExp(buf_WorkExp);
		SetDegree(buf_Degree);
		SetFacultyName(buf_FacultyName);
		SetFacultyName(check.GetFacultyName());
		thehuman = buf_human;
		return (false);
	}
}

//Метод ввода полей объекта класса из консоли
bool teacher::Read()
{
	//создаём объект класса teacher для проверки формата входных данных
	teacher check;

	//буферный переменная типа int 
	//для проверки формата входных данных 
	int buf_int;

	//проверка на формат входных данных
	printf("Enter working experience:\n");
	if (scanf("%d", &buf_int) != 1)
		return (true);
	else
	{
		//попытка записи в поле объекта
		if (check.SetWorkExp(buf_int))
			return (true);
		else
		{
			//создаём буферную строку для проверки формата входных данных
			char buf_string[40];
			rewind(stdin);
			printf("Enter scientific degree:\n");
			fgets(buf_string, 40, stdin);
			//если строка короче 40, то заменить "перенос на новую строку" "концом строки"
			if (buf_string[strlen(buf_string) - 1] == '\n')
				buf_string[strlen(buf_string) - 1] = '\0';
			//если строка длиннее 40, то очистить входной поток
			else rewind(stdin);

			//попытка записи в поле объекта
			if (check.SetDegree(buf_string))
				return (true);
			else
			{
				printf("Enter faculty name:\n");
				fgets(buf_string, 30, stdin);
				//если строка короче 30, то заменить "перенос на новую строку" "концом строки"
				if (buf_string[strlen(buf_string) - 1] == '\n')
					buf_string[strlen(buf_string) - 1] = '\0';
				//если строка длиннее 30, то очистить входной поток
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
						SetWorkExp(check.GetWorkExp());
						SetDegree(check.GetDegree());
						SetFacultyName(check.GetFacultyName());
						thehuman = check.thehuman;
						return(false);
					}
				}
			}
		}
	}
}

//Метод вывода содержимого объекта класса в консоль
void teacher::Display()
{
	printf("working experience: %d years\n", WorkExp);
	printf("scientific degree: %s\n",Degree);
	printf("faculty name: %s\n", FacultyName);
	thehuman.Display();
}
