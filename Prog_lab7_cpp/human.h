#include "FIO.h"

//������ �� ��������������� ���������
#ifndef HUMAN_H
#define HUMAN_H

class human {
private:
	int id;		//id
	int age;	//�������
	int height; //����
	float weight; //���
	char gender[2];  //���

public:
	FIO human_FIO;	  //������ ������ FIO

	//������ ���������... 
	bool SetId(int buf); //id
	bool SetAge(int buf);//��������
	bool SetHeight(int buf);  //�����
	bool SetWeight(float buf);//����
	bool SetGender(char buf[]); //����

	//������ ����������...
	int GetId(); //id
	int GetAge();//��������
	int GetHeight();  //�����
	float GetWeight();//����
	char* GetGender(); //����
	
	//����� ������������� ������� ������
	bool Init(int buf_id, int buf_age, int buf_height, float buf_weight,char buf_gender[], FIO buf_FIO);

	//����� ����� ����� ������� ������ �� �������
	bool Read();

	//����� ������ ������� ������ � �������
	void Display();
};

#endif HUMAN_H
