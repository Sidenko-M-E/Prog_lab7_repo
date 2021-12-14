#include "human.h"

class student {
private:
	int course;  //курс обучения
	char EduProg[FIO_fields_size / 3 * 2];//учебная программа
	char Group[FIO_fields_size / 3];	  //название группы
	char FacultyName[FIO_fields_size];	  //название факультета

public:
	human thehuman; //объект класса "human"

	//Методы установки...
	bool SetCourse(int buf);//курса обучения
	bool SetEduProg(char buf_string[]); //учебной программы
	bool SetGroup(char buf_string[]);	//названия группы
	bool SetFacultyName(char buf_string[]);//названия факультета

	//Методы извлечения...
	int GetCourse();//курса обучения
	char* GetEduProg(); //учебной программы
	char* GetGroup();	//названия группы
	char* GetFacultyName();//названия факультета

	//Метод  инициализации объекта класса
	bool Init(int buf_course, char buf_EduProg[], char buf_Group[], char buf_FacultyName[], human buf_human);

	//Метод ввода полей объекта класса из консоли
	bool Read();

	//Метод вывода содержимого объекта класса в консоль
	void Display();
};
