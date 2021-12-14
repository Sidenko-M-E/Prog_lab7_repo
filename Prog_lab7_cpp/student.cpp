#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "student.h"

//����� ��������� ����� ��������
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

//����� ��������� ������� ���������
bool student::SetEduProg(char buf_string[])
{
	//������� ������� ������
	if (strlen(buf_string) > (FIO_fields_size / 3 * 2))
		buf_string[(FIO_fields_size / 3 * 2) - 1] = '\0';

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
	strcpy(EduProg, buf_string);
	return (false);
}

//����� ��������� �������� ������
bool student::SetGroup(char buf_string[])
{
	//������� ������� ������
	if (strlen(buf_string) > (FIO_fields_size / 3))
		buf_string[(FIO_fields_size / 3) - 1] = '\0';

	//�������� �� ���� ������ ������
	if (strlen(buf_string) == 0)
		return (true);

	//����������� ������� ������������ ��������
	char invalid_symbols[] = "!@#$%^&*()_+=\"�;:?*,./'][{}<>~` ";
	int invalid_symbols_lenght = 32;

	//������������ ��������� ������� ������ � ������� ������������ ��������
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//����������� ������� ������ � ���� �������,
	//��� �������� ����������� ��������
	strcpy(Group, buf_string);
	return (false);
}

//����� ��������� �������� ����������
bool student::SetFacultyName(char buf_string[])
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
	strcpy(FacultyName, buf_string);
	return (false);
}

//����� ���������� ����� ��������
int student::GetCourse()
{
	int buf = course;
	return (buf);
}

//����� ���������� ������� ���������
char* student::GetEduProg()
{
	char* buf_string = (char*)calloc(FIO_fields_size / 3 * 2, sizeof(char));
	strcpy(buf_string, EduProg);
	return (buf_string);
}

//����� ���������� �������� ������
char* student::GetGroup()
{
	char* buf_string = (char*)calloc(FIO_fields_size / 3, sizeof(char));
	strcpy(buf_string, Group);
	return (buf_string);
}

//����� ���������� �������� ����������
char* student::GetFacultyName()
{
	char* buf_string = (char*)calloc(FIO_fields_size, sizeof(char));
	strcpy(buf_string, FacultyName);
	return (buf_string);
}

//�����  ������������� ������� ������
bool student::Init(int buf_course, char buf_EduProg[], char buf_Group[], char buf_FacultyName[], human buf_human)
{
	//������ ������ ������ student ��� �������� ������� ������� ������
	student check;

	//�������� �� ������ ����� human??????????
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

//����� ����� ����� ������� ������ �� �������
bool student::Read()
{
	//������ ������ ������ student ��� �������� ������� ������� ������
	student check;

	//�������� ���������� ���� int 
	//��� �������� ������� ������� ������ 
	int buf_int;

	//�������� �� ������ ������� ������
	printf("Enter course:\n");
	if (scanf("%d", &buf_int) != 1)
		return (true);
	else
	{
		//������� ������ � ���� �������
		if (check.SetCourse(buf_int))
			return (true);
		else
		{
			//������ �������� ������ ��� �������� ������� ������� ������
			char buf_string[FIO_fields_size];
			rewind(stdin);
			printf("Enter education programm:\n");
			fgets(buf_string, FIO_fields_size / 3 * 2, stdin);
			//���� ������ ������ 20, �� �������� "������� �� ����� ������" "������ ������"
			if (buf_string[strlen(buf_string) - 1] == '\n')
				buf_string[strlen(buf_string) - 1] = '\0';
			//���� ������ ������� 20, �� �������� ������� �����
			else rewind(stdin);

			//������� ������ � ���� �������
			if (check.SetEduProg(buf_string))
				return (true);
			else
			{
				printf("Enter group:\n");
				fgets(buf_string, FIO_fields_size / 3, stdin);
				//���� ������ ������ 10, �� �������� "������� �� ����� ������" "������ ������"
				if (buf_string[strlen(buf_string) - 1] == '\n')
					buf_string[strlen(buf_string) - 1] = '\0';
				//���� ������ ������� 10, �� �������� ������� �����
				else rewind(stdin);

				//������� ������ � ���� �������
				if (check.SetGroup(buf_string))
					return (true);
				else
				{
					printf("Enter faculty name:\n");
					fgets(buf_string, FIO_fields_size, stdin);
					//���� ������ ������ 10, �� �������� "������� �� ����� ������" "������ ������"
					if (buf_string[strlen(buf_string) - 1] == '\n')
						buf_string[strlen(buf_string) - 1] = '\0';
					//���� ������ ������� 10, �� �������� ������� �����
					else rewind(stdin);

					//������� ������ � ���� �������
					if (check.SetFacultyName(buf_string))
						return (true);
					else
					{
						//������� ������ � ������
						if (check.thehuman.Read())
							return (true);

						//����� ��� �������� ��������,
						//����� ��������� ������ � ������� ������
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

//����� ������ ����������� ������� ������ � �������
void student::Display()
{
	printf("course: %d\n", course);
	printf("direction of preparation: %s\n", EduProg);
	printf("group: %s\n", Group);
	printf("faculty name: %s\n", FacultyName);
	thehuman.Display();
}
