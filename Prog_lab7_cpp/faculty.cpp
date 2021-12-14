#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "faculty.h"

//����� ��������� �������� ����������
bool faculty::SetFacultyName(char buf_string[])
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

//����� ��������� ���-�� ���������
bool faculty::SetQuantityOfStudents(int buf)
{
	if (buf < 0 || buf > 1000)
		return (true);
	else
	{
		QuantityOfStudents = buf;
		return (false);
	}
}

//����� ��������� ���-�� ����������
bool faculty::SetQuantityOfBachelors(int buf)
{
	if (buf < 0 || buf > 1000)
		return (true);
	else
	{
		QuantityOfBachelors = buf;
		return (false);
	}
}

//����� ��������� ���-�� ���������
bool faculty::SetQuantityOfMasters(int buf)
{
	if (buf < 0 || buf > 1000)
		return (true);
	else
	{
		QuantityOfMasters = buf;
		return (false);
	}
}

//����� ��������� ���-�� ��������
bool faculty::SetQuantityOfTeachers(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		QuantityOfTeachers = buf;
		return (false);
	}
}

//����� ��������� ���-�� ���������� ����
bool faculty::SetQuantityOfCandidates(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		QuantityOfCandidates = buf;
		return (false);
	}
}

//����� ��������� ���-�� �������� ����
bool faculty::SetQuantityOfDoctors(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		QuantityOfDoctors = buf;
		return (false);
	}
}

//����� ��������� ���-�� ���������
bool faculty::SetQuantityOfDisciplines(int buf)
{
	if (buf < 0 || buf > 100)
		return (true);
	else
	{
		QuantityOfDisciplines = buf;
		return (false);
	}
}

//����� ��������� ���������� � ���������
bool faculty::SetStudentsInfo(int all_quan, int bach_quan, int mast_quan)
{
	if (all_quan < 0 || all_quan > 1000 || bach_quan < 0 || bach_quan > 1000 || mast_quan < 0 || mast_quan > 1000)
		return (true);
	else
	{
		QuantityOfStudents = all_quan;
		QuantityOfBachelors = bach_quan;
		QuantityOfMasters = mast_quan;
		return (false);
	}
}

//����� ��������� ���������� � ��������������
bool faculty::SetTeachersInfo(int all_quan, int cand_quan, int doct_quan)
{
	if (all_quan < 0 || all_quan > 100 || cand_quan < 0 || cand_quan > 100 || doct_quan < 0 || doct_quan > 100)
		return (true);
	else
	{
		QuantityOfTeachers = all_quan;
		QuantityOfCandidates = cand_quan;
		QuantityOfDoctors = doct_quan;
		return (false);
	}
}

//����� ���������� �������� ����������
char* faculty::GetFacultyName()
{
	char* buf_string = (char*)calloc(30, sizeof(char));
	strcpy(buf_string, FacultyName);
	return (buf_string);
}

//����� ���������� ���-�� ���������
int faculty::GetQuantityOfStudents()
{
	int buf = QuantityOfStudents;
	return (buf);
}

//����� ���������� ���-�� ����������
int faculty::GetQuantityOfBachelors()
{
	int buf = QuantityOfBachelors;
	return (buf);
}

//����� ���������� ���-�� ���������
int faculty::GetQuantityOfMasters()
{
	int buf = QuantityOfMasters;
	return (buf);
}

//����� ���������� ���-�� ��������
int faculty::GetQuantityOfTeachers()
{
	int buf = QuantityOfTeachers;
	return (buf);
}

//����� ���������� ���-�� ���������� ����
int faculty::GetQuantityOfCandidates()
{
	int buf = QuantityOfCandidates;
	return (buf);
}

//����� ���������� ���-�� �������� ����
int faculty::GetQuantityOfDoctors()
{
	int buf = QuantityOfDoctors;
	return (buf);
}

//����� ���������� ���-�� ���������
int faculty::GetQuantityOfDisciplines()
{
	int buf = QuantityOfDisciplines;
	return (buf);
}

//����� �������� ����������� ���-�� ��������� ����� �������� !!!!!
double faculty::ProcentOfMasters()
{
	return(((double)QuantityOfMasters) / ((double)QuantityOfStudents) * 100);
}

//����� �������� ����������� ���-�� �������� ���� ����� �������������� !!!!!
double faculty::ProcentOfDoctors()
{
	return(((double)QuantityOfDoctors) / ((double)QuantityOfTeachers) * 100);
}

//����� �������� ���-�� ���������, ������������ �� ������ ������������� !!!!!
double faculty::ProcOfStudToTeach()
{
	return(((double)QuantityOfStudents) / ((double)QuantityOfTeachers));
}


bool faculty::Init(char buf_FacultyName[], int stud_quan, int bach_quan, int mast_quan, int teac_quan, int cand_quan, int doct_quan, int disc_quan)
{

	//������ ������ ������ faculty ��� �������� ������� ������� ������
	faculty check;

	//�������� �� ������ ����� 
	if (check.SetFacultyName(buf_FacultyName) || check.SetQuantityOfStudents(stud_quan) ||
		check.SetQuantityOfBachelors(bach_quan) || check.SetQuantityOfMasters(mast_quan) ||
		check.SetQuantityOfTeachers(teac_quan) || check.SetQuantityOfCandidates(cand_quan) ||
		check.SetQuantityOfDoctors(doct_quan) || check.SetQuantityOfDisciplines(disc_quan))
		return (true);
	else
	{
		SetFacultyName(buf_FacultyName);
		SetQuantityOfStudents(stud_quan);
		SetQuantityOfBachelors(bach_quan);
		SetQuantityOfMasters(mast_quan);
		SetQuantityOfTeachers(teac_quan);
		SetQuantityOfCandidates(cand_quan);
		SetQuantityOfDoctors(doct_quan);
		SetQuantityOfDisciplines(disc_quan);
		return (false);
	}
}

//����� ����� ����� ������� ������ �� �������
bool faculty::Read()
{
	//������ ������ ������ faculty ��� �������� ������� ������� ������
	faculty check;

	//������ �������� ������ ��� �������� ������� ������� ������
	char buf_string[30];

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
		//�������� ���������� ���� int 
		//��� �������� ������� ������� ������ 
		int buf_int;

		//�������� �� ������ ������� ������
		printf("Enter quantity of students:\n");
		if (scanf("%d", &buf_int) != 1)
			return (true);
		else
		{
			//������� ������ � ���� �������
			if (check.SetQuantityOfStudents(buf_int))
				return (true);
			else
			{
				//�������� �� ������ ������� ������
				printf("Enter quantity of bachelors:\n");
				if (scanf("%d", &buf_int) != 1)
					return (true);
				else
				{
					//������� ������ � ���� �������
					if (check.SetQuantityOfBachelors(buf_int))
						return (true);
					else
					{
						//�������� �� ������ ������� ������
						printf("Enter quantity of masters:\n");
						if (scanf("%d", &buf_int) != 1)
							return (true);
						else
						{
							//������� ������ � ���� �������
							if (check.SetQuantityOfMasters(buf_int))
								return (true);
							else
							{
								//�������� �� ������ ������� ������
								printf("Enter quantity of teachers:\n");
								if (scanf("%d", &buf_int) != 1)
									return (true);
								else
								{
									//������� ������ � ���� �������
									if (check.SetQuantityOfTeachers(buf_int))
										return (true);
									else
									{
										//�������� �� ������ ������� ������
										printf("Enter quantity of candidates:\n");
										if (scanf("%d", &buf_int) != 1)
											return (true);
										else
										{
											//������� ������ � ���� �������
											if (check.SetQuantityOfCandidates(buf_int))
												return (true);
											else
											{
												//�������� �� ������ ������� ������
												printf("Enter quantity of doctors:\n");
												if (scanf("%d", &buf_int) != 1)
													return (true);
												else
												{
													//������� ������ � ���� �������
													if (check.SetQuantityOfDoctors(buf_int))
														return (true);
													else
													{
														//�������� �� ������ ������� ������
														printf("Enter quantity of disciplines:\n");
														if (scanf("%d", &buf_int) != 1)
															return (true);
														else
														{
															//������� ������ � ���� �������
															if (check.SetQuantityOfDisciplines(buf_int))
																return (true);
															else
															{
																SetFacultyName(check.GetFacultyName());
																SetQuantityOfStudents(check.GetQuantityOfStudents());
																SetQuantityOfBachelors(check.GetQuantityOfBachelors());
																SetQuantityOfMasters(check.GetQuantityOfMasters());
																SetQuantityOfTeachers(check.GetQuantityOfTeachers());
																SetQuantityOfCandidates(check.GetQuantityOfCandidates());
																SetQuantityOfDoctors(check.GetQuantityOfDoctors());
																SetQuantityOfDisciplines(check.GetQuantityOfDisciplines());
																return (false);
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

//����� ������ ����������� ������� ������ � �������
void faculty::Display()
{
	printf("faculty name: %s\n", FacultyName);
	printf("quantity of students: %d\n", QuantityOfStudents);
	printf("quantity of bachelors: %d\n", QuantityOfBachelors);
	printf("quantity of masters: %d\n\n", QuantityOfMasters);

	printf("quantity of teachers: %d\n", QuantityOfTeachers);
	printf("quantity of candidates: %d\n", QuantityOfCandidates);
	printf("quantity of doctors: %d\n\n", QuantityOfDoctors);

	printf("quantity of disciplines: %d\n", QuantityOfDisciplines);
}
