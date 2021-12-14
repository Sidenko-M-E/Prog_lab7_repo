//Защита от переопредления структуры
#ifndef FIO_H
#define FIO_H

#define _CRT_SECURE_NO_WARNINGS
#define FIO_fields_size 30

class FIO {
private:
	char SurName[FIO_fields_size]; //Фамилия
	char Name[FIO_fields_size]; //Имя
	char Patronymic[FIO_fields_size]; //Отчество

public:
	//Методы установки...
	bool SetSurName(char buf_string[]);//фамилии
	bool SetName(char buf_string[]);	//имени
	bool SetPatronymic(char buf_string[]);//отчества

	//Методы извлечения...
	char* GetSurName();//фамилии
	char* GetName();	//имени
	char* GetPatronymic();//отчества

	//Метод инициализации структуры
	bool Init(char buf_surname[], char buf_name[], char buf_patronymic[]);

	//Метод ввода полей объекта класса из консоли
	bool Read();

	//Метод вывода объекта класса в консоль
	void Display();
};
#endif FIO_H
