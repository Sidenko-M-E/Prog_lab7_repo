#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "FIO.h"

//Защита от переопределения методов структуры
#ifndef FIO_CPP
#define FIO_CPP

//Метод установки фамилии
bool FIO::SetSurName(char buf_string[]) //проверка на \n ????
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
	strcpy(SurName, buf_string);
	return (false);
}

//Метод  установки имени
bool FIO::SetName(char buf_string[]) 
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
	strcpy(Name, buf_string);
	return (false);
}

//Метод  установки отчества
bool FIO::SetPatronymic(char buf_string[]) 
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
	strcpy(Patronymic, buf_string);
	return (false);
}

//Метод извлечения фамилии
char* FIO::GetSurName()
{
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, SurName);
	return (buf_string);
}

//Метод извлечения имени
char* FIO::GetName() 
{ 
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, Name);
	return (buf_string);
}

//Метод извлечения отчества
char* FIO::GetPatronymic() 
{ 
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, Patronymic);
	return (buf_string);
}

//Метод  инициализации объекта класса
bool FIO::Init(char buf_surname[], char buf_name[], char buf_patronymic[])
{
	//создаём объект класса FIO для проверки формата входных данных
	FIO check;

	//проверка на формат ввода
	if (check.SetSurName(buf_surname) || check.SetName(buf_name) || check.SetPatronymic(buf_patronymic))
		return (true);
	else
	{
		SetSurName(buf_surname);
		SetName(buf_name);
		SetPatronymic(buf_patronymic);
		return (false);
	}
}

//Метод ввода полей объекта класса из консоли
bool FIO::Read()
{
	//создаём объект класса FIO для проверки формата входных данных
	FIO check;

	//создаём буферную строку для проверки формата входных данных
	char buf_string[FIO_fields_size];

	printf("Enter surname:\n");
	fgets(buf_string, FIO_fields_size, stdin);
	//если строка короче 30, то заменить "перенос на новую строку" "концом строки"
	if (buf_string[strlen(buf_string) - 1] == '\n')
		buf_string[strlen(buf_string) - 1] = '\0';
	//если строка длиннее 30, то очистить входной поток
	else rewind(stdin);

	if (check.SetSurName(buf_string))
		return (true);
	else 
	{
		printf("Enter name:\n");
		fgets(buf_string, FIO_fields_size, stdin);
		//если строка короче 30, то заменить "перенос на новую строку" "концом строки"
		if (buf_string[strlen(buf_string) - 1] == '\n')
			buf_string[strlen(buf_string) - 1] = '\0';
		//если строка длиннее 30, то очистить входной поток
		else rewind(stdin);

		if (check.SetName(buf_string))
			return(true);
		else
		{
			printf("Enter patronymic:\n");
			fgets(buf_string, FIO_fields_size, stdin);
			//если строка короче 30, то заменить "перенос на новую строку" "концом строки"
			if (buf_string[strlen(buf_string) - 1] == '\n')
				buf_string[strlen(buf_string) - 1] = '\0';
			//если строка длиннее 30, то очистить входной поток
			else rewind(stdin);

			if (check.SetPatronymic(buf_string))
				return(true);

			//если все проверки на формат успешно пройдены, то
			//записываем полученные данные в поля объекта
			else
			{
				SetSurName(check.GetSurName());
				SetName(check.GetName());
				SetPatronymic(check.GetPatronymic());
				return (false);
			}
		}
	}
}

//Метод вывода содержимого объекта класса в консоль
void FIO::Display()
{
	printf("FIO: %s %s %s\n", SurName, Name, Patronymic);
}

#endif FIO_CPP
