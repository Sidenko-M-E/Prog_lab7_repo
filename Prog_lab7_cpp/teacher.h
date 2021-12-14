#include "human.h"

class teacher {
private:
	int WorkExp;//рабочий стаж
	char Degree[40];//ученая степень
	char FacultyName[30];//название факультета

public:
	human thehuman; //подструктура "human"

	//Методы установки...
	bool SetWorkExp(int buf);//рабочего стажа
	bool SetDegree(char buf_string[]);//ученой степени
	bool SetFacultyName(char buf_string[]);//названия факультета

	//Методы извлечения...
	int GetWorkExp();//рабочего стажа
	char* GetDegree();//ученой степени
	char* GetFacultyName();//названия факультета

	//Метод  инициализации объекта класса
	bool Init(int buf_WorkExp, char buf_Degree[], char buf_FacultyName[], human buf_human);

	//Метод ввода полей объекта класса из консоли
	bool Read();

	//Метод вывода содержимого объекта класса в консоль
	void Display();
};
