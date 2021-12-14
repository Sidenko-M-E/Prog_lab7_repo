#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "teacher.h"

//����� ��������� �������� �����
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

//����� ��������� ������ �������
bool teacher::SetDegree(char buf_string[])
{
	//������� ������� ������
	if (strlen(buf_string) > 40)
		buf_string[40 - 1] = '\0';

	//�������� �� ���� ������ ������
	if (strlen(buf_string) == 0)
		return (true);

	//����������� ������� ������������ ��������
	char invalid_symbols[] = "!@#$%^&*()_+1234567890-=\"�;:?*,./'][{}<>~`";
	int invalid_symbols_lenght = 42;

	//������������ ��������� ������� ������ � ������� ������������ ��������
	int buf_len = strlen(buf_string);
	for (int i = 0; i < buf_len; i++)
		for (int j = 0; j < invalid_symbols_lenght; j++)
			if (buf_string[i] == invalid_symbols[j])
				return(true);

	//����������� ������� ������ � ���� �������,
	//��� �������� ����������� ��������
	strcpy(Degree, buf_string);
	return (false);
}

//����� ��������� �������� ����������
bool teacher::SetFacultyName(char buf_string[])
{
	//������� ������� ������
	if (strlen(buf_string) > 30)
		buf_string[30 - 1] = '\0';

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

//����� ���������� �������� �����
int teacher::GetWorkExp()
{
	int buf = WorkExp;
	return (buf);
}

//����� ���������� ������ �������
char* teacher::GetDegree()
{
	char* buf_string = (char*)calloc(40, sizeof(char));
	strcpy(buf_string, Degree);
	return (buf_string);
}

//����� ���������� �������� ����������
char* teacher::GetFacultyName()
{
	char* buf_string = (char*)calloc(30, sizeof(char));
	strcpy(buf_string, FacultyName);
	return (buf_string);
}

//�����  ������������� ������� ������
bool teacher::Init(int buf_WorkExp, char buf_Degree[], char buf_FacultyName[], human buf_human)
{
	//������ ������ ������ human ��� �������� ������� ������� ������
	teacher check;

	//�������� �� ������ ����� human??????????
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

//����� ����� ����� ������� ������ �� �������
bool teacher::Read()
{
	//������ ������ ������ teacher ��� �������� ������� ������� ������
	teacher check;

	//�������� ���������� ���� int 
	//��� �������� ������� ������� ������ 
	int buf_int;

	//�������� �� ������ ������� ������
	printf("Enter working experience:\n");
	if (scanf("%d", &buf_int) != 1)
		return (true);
	else
	{
		//������� ������ � ���� �������
		if (check.SetWorkExp(buf_int))
			return (true);
		else
		{
			//������ �������� ������ ��� �������� ������� ������� ������
			char buf_string[40];
			rewind(stdin);
			printf("Enter scientific degree:\n");
			fgets(buf_string, 40, stdin);
			//���� ������ ������ 40, �� �������� "������� �� ����� ������" "������ ������"
			if (buf_string[strlen(buf_string) - 1] == '\n')
				buf_string[strlen(buf_string) - 1] = '\0';
			//���� ������ ������� 40, �� �������� ������� �����
			else rewind(stdin);

			//������� ������ � ���� �������
			if (check.SetDegree(buf_string))
				return (true);
			else
			{
				printf("Enter faculty name:\n");
				fgets(buf_string, 30, stdin);
				//���� ������ ������ 30, �� �������� "������� �� ����� ������" "������ ������"
				if (buf_string[strlen(buf_string) - 1] == '\n')
					buf_string[strlen(buf_string) - 1] = '\0';
				//���� ������ ������� 30, �� �������� ������� �����
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

//����� ������ ����������� ������� ������ � �������
void teacher::Display()
{
	printf("working experience: %d years\n", WorkExp);
	printf("scientific degree: %s\n",Degree);
	printf("faculty name: %s\n", FacultyName);
	thehuman.Display();
}
