#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "faculty.h"

//Метод установки названия факультета
bool faculty::SetFacultyName(char buf_string[])
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

//Метод установки кол-ва студентов
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

//Метод установки кол-ва бакалавров
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

//Метод установки кол-ва магистров
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

//Метод установки кол-ва учителей
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

//Метод установки кол-ва кандидатов наук
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

//Метод установки кол-ва докторов наук
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

//Метод установки кол-ва дисциплин
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

//Метод установки информации о студентах
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

//Метод установки информации о преподавателях
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

//Метод извлечения навзания факультета
char* faculty::GetFacultyName()
{
	char* buf_string = (char*)calloc(30, sizeof(char));
	strcpy(buf_string, FacultyName);
	return (buf_string);
}

//Метод извлечения кол-ва студентов
int faculty::GetQuantityOfStudents()
{
	int buf = QuantityOfStudents;
	return (buf);
}

//Метод извлечения кол-ва бакалавров
int faculty::GetQuantityOfBachelors()
{
	int buf = QuantityOfBachelors;
	return (buf);
}

//Метод извлечения кол-ва магистров
int faculty::GetQuantityOfMasters()
{
	int buf = QuantityOfMasters;
	return (buf);
}

//Метод извлечения кол-ва учителей
int faculty::GetQuantityOfTeachers()
{
	int buf = QuantityOfTeachers;
	return (buf);
}

//Метод извлечения кол-ва кандидатов наук
int faculty::GetQuantityOfCandidates()
{
	int buf = QuantityOfCandidates;
	return (buf);
}

//Метод извлечения кол-ва докторов наук
int faculty::GetQuantityOfDoctors()
{
	int buf = QuantityOfDoctors;
	return (buf);
}

//Метод извлечения кол-ва дисциплин
int faculty::GetQuantityOfDisciplines()
{
	int buf = QuantityOfDisciplines;
	return (buf);
}

//Метод подсчёта процентного кол-ва магистров среди учащихся !!!!!
double faculty::ProcentOfMasters()
{
	return(((double)QuantityOfMasters) / ((double)QuantityOfStudents) * 100);
}

//Метод подсчёта процентного кол-ва докторов наук среди преподавателей !!!!!
double faculty::ProcentOfDoctors()
{
	return(((double)QuantityOfDoctors) / ((double)QuantityOfTeachers) * 100);
}

//Метод подсчёта кол-ва студентов, приходящихся на одного преподавателя !!!!!
double faculty::ProcOfStudToTeach()
{
	return(((double)QuantityOfStudents) / ((double)QuantityOfTeachers));
}


bool faculty::Init(char buf_FacultyName[], int stud_quan, int bach_quan, int mast_quan, int teac_quan, int cand_quan, int doct_quan, int disc_quan)
{

	//создаём объект класса faculty для проверки формата входных данных
	faculty check;

	//проверка на формат ввода 
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

//Метод ввода полей объекта класса из консоли
bool faculty::Read()
{
	//создаём объект класса faculty для проверки формата входных данных
	faculty check;

	//создаём буферную строку для проверки формата входных данных
	char buf_string[30];

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
		//буферный переменная типа int 
		//для проверки формата входных данных 
		int buf_int;

		//проверка на формат входных данных
		printf("Enter quantity of students:\n");
		if (scanf("%d", &buf_int) != 1)
			return (true);
		else
		{
			//попытка записи в поле объекта
			if (check.SetQuantityOfStudents(buf_int))
				return (true);
			else
			{
				//проверка на формат входных данных
				printf("Enter quantity of bachelors:\n");
				if (scanf("%d", &buf_int) != 1)
					return (true);
				else
				{
					//попытка записи в поле объекта
					if (check.SetQuantityOfBachelors(buf_int))
						return (true);
					else
					{
						//проверка на формат входных данных
						printf("Enter quantity of masters:\n");
						if (scanf("%d", &buf_int) != 1)
							return (true);
						else
						{
							//попытка записи в поле объекта
							if (check.SetQuantityOfMasters(buf_int))
								return (true);
							else
							{
								//проверка на формат входных данных
								printf("Enter quantity of teachers:\n");
								if (scanf("%d", &buf_int) != 1)
									return (true);
								else
								{
									//попытка записи в поле объекта
									if (check.SetQuantityOfTeachers(buf_int))
										return (true);
									else
									{
										//проверка на формат входных данных
										printf("Enter quantity of candidates:\n");
										if (scanf("%d", &buf_int) != 1)
											return (true);
										else
										{
											//попытка записи в поле объекта
											if (check.SetQuantityOfCandidates(buf_int))
												return (true);
											else
											{
												//проверка на формат входных данных
												printf("Enter quantity of doctors:\n");
												if (scanf("%d", &buf_int) != 1)
													return (true);
												else
												{
													//попытка записи в поле объекта
													if (check.SetQuantityOfDoctors(buf_int))
														return (true);
													else
													{
														//проверка на формат входных данных
														printf("Enter quantity of disciplines:\n");
														if (scanf("%d", &buf_int) != 1)
															return (true);
														else
														{
															//попытка записи в поле объекта
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

//Метод вывода содержимого объекта класса в консоль
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
