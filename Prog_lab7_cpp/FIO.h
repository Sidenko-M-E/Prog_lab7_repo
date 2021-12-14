//������ �� �������������� ���������
#ifndef FIO_H
#define FIO_H

#define _CRT_SECURE_NO_WARNINGS
#define FIO_fields_size 30

class FIO {
private:
	char SurName[FIO_fields_size]; //�������
	char Name[FIO_fields_size]; //���
	char Patronymic[FIO_fields_size]; //��������

public:
	//������ ���������...
	bool SetSurName(char buf_string[]);//�������
	bool SetName(char buf_string[]);	//�����
	bool SetPatronymic(char buf_string[]);//��������

	//������ ����������...
	char* GetSurName();//�������
	char* GetName();	//�����
	char* GetPatronymic();//��������

	//����� ������������� ���������
	bool Init(char buf_surname[], char buf_name[], char buf_patronymic[]);

	//����� ����� ����� ������� ������ �� �������
	bool Read();

	//����� ������ ������� ������ � �������
	void Display();
};
#endif FIO_H
