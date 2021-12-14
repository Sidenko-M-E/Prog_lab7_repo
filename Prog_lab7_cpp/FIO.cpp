#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "FIO.h"

//������ �� ��������������� ������� ���������
#ifndef FIO_CPP
#define FIO_CPP

//����� ��������� �������
bool FIO::SetSurName(char buf_string[]) //�������� �� \n ????
{ 
	//������� ������� ������
	if (strlen(buf_string) > FIO_fields_size)
		buf_string[FIO_fields_size - 1] = '\0';

	//�������� �� ���� ������ ������
	if (strlen(buf_string) == 0)
		return (true);

	//����������� ������� ������������ ��������
	char invalid_symbols[] = "!@#$%^&*()_+1234567890-=\"�;:?*,./'][{}<>~` ";
	int invalid_symbols_lenght = 43;

	//������������ ��������� ������� ������ � ������� ������������ ��������
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++) 
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//����������� ������� ������ � ���� �������,
	//��� �������� ����������� ��������
	strcpy(SurName, buf_string);
	return (false);
}

//�����  ��������� �����
bool FIO::SetName(char buf_string[]) 
{
	//������� ������� ������
	if (strlen(buf_string) > FIO_fields_size)
		buf_string[FIO_fields_size - 1] = '\0';

	//�������� �� ���� ������ ������
	if (strlen(buf_string) == 0)
		return (true);

	//����������� ������� ������������ ��������
	char invalid_symbols[] = "!@#$%^&*()_+1234567890-=\"�;:?*,./'][{}<>~` ";
	int invalid_symbols_lenght = 43;

	//������������ ��������� ������� ������ � ������� ������������ ��������
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//����������� ������� ������ � ���� �������,
	//��� �������� ����������� ��������
	strcpy(Name, buf_string);
	return (false);
}

//�����  ��������� ��������
bool FIO::SetPatronymic(char buf_string[]) 
{
	//������� ������� ������
	if (strlen(buf_string) > FIO_fields_size)
		buf_string[FIO_fields_size - 1] = '\0';

	//�������� �� ���� ������ ������
	if (strlen(buf_string) == 0)
		return (true);

	//����������� ������� ������������ ��������
	char invalid_symbols[] = "!@#$%^&*()_+1234567890-=\"�;:?*,./'][{}<>~` ";
	int invalid_symbols_lenght = 43;

	//������������ ��������� ������� ������ � ������� ������������ ��������
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//����������� ������� ������ � ���� �������,
	//��� �������� ����������� ��������
	strcpy(Patronymic, buf_string);
	return (false);
}

//����� ���������� �������
char* FIO::GetSurName()
{
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, SurName);
	return (buf_string);
}

//����� ���������� �����
char* FIO::GetName() 
{ 
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, Name);
	return (buf_string);
}

//����� ���������� ��������
char* FIO::GetPatronymic() 
{ 
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, Patronymic);
	return (buf_string);
}

//�����  ������������� ������� ������
bool FIO::Init(char buf_surname[], char buf_name[], char buf_patronymic[])
{
	//������ ������ ������ FIO ��� �������� ������� ������� ������
	FIO check;

	//�������� �� ������ �����
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

//����� ����� ����� ������� ������ �� �������
bool FIO::Read()
{
	//������ ������ ������ FIO ��� �������� ������� ������� ������
	FIO check;

	//������ �������� ������ ��� �������� ������� ������� ������
	char buf_string[FIO_fields_size];

	printf("Enter surname:\n");
	fgets(buf_string, FIO_fields_size, stdin);
	//���� ������ ������ 30, �� �������� "������� �� ����� ������" "������ ������"
	if (buf_string[strlen(buf_string) - 1] == '\n')
		buf_string[strlen(buf_string) - 1] = '\0';
	//���� ������ ������� 30, �� �������� ������� �����
	else rewind(stdin);

	if (check.SetSurName(buf_string))
		return (true);
	else 
	{
		printf("Enter name:\n");
		fgets(buf_string, FIO_fields_size, stdin);
		//���� ������ ������ 30, �� �������� "������� �� ����� ������" "������ ������"
		if (buf_string[strlen(buf_string) - 1] == '\n')
			buf_string[strlen(buf_string) - 1] = '\0';
		//���� ������ ������� 30, �� �������� ������� �����
		else rewind(stdin);

		if (check.SetName(buf_string))
			return(true);
		else
		{
			printf("Enter patronymic:\n");
			fgets(buf_string, FIO_fields_size, stdin);
			//���� ������ ������ 30, �� �������� "������� �� ����� ������" "������ ������"
			if (buf_string[strlen(buf_string) - 1] == '\n')
				buf_string[strlen(buf_string) - 1] = '\0';
			//���� ������ ������� 30, �� �������� ������� �����
			else rewind(stdin);

			if (check.SetPatronymic(buf_string))
				return(true);

			//���� ��� �������� �� ������ ������� ��������, ��
			//���������� ���������� ������ � ���� �������
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

//����� ������ ����������� ������� ������ � �������
void FIO::Display()
{
	printf("FIO: %s %s %s\n", SurName, Name, Patronymic);
}

#endif FIO_CPP
