#include "FIO.h"

//Защита от переопределения структуры
#ifndef HUMAN_H
#define HUMAN_H

class human {
private:
	int id;		//id
	int age;	//возраст
	int height; //рост
	float weight; //вес
	char gender[2];  //пол

public:
	FIO human_FIO;	  //объект класса FIO

	//Методы установки... 
	bool SetId(int buf); //id
	bool SetAge(int buf);//возраста
	bool SetHeight(int buf);  //роста
	bool SetWeight(float buf);//веса
	bool SetGender(char buf[]); //пола

	//Методы извлечения...
	int GetId(); //id
	int GetAge();//возраста
	int GetHeight();  //роста
	float GetWeight();//веса
	char* GetGender(); //пола
	
	//Метод инициализации объекта класса
	bool Init(int buf_id, int buf_age, int buf_height, float buf_weight,char buf_gender[], FIO buf_FIO);

	//Метод ввода полей объекта класса из консоли
	bool Read();

	//Метод вывода объекта класса в консоль
	void Display();
};

#endif HUMAN_H
