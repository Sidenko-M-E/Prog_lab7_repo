#include "human.h"

class student {
private:
	int course;  //���� ��������
	char EduProg[FIO_fields_size / 3 * 2];//������� ���������
	char Group[FIO_fields_size / 3];	  //�������� ������
	char FacultyName[FIO_fields_size];	  //�������� ����������

public:
	human thehuman; //������ ������ "human"

	//������ ���������...
	bool SetCourse(int buf);//����� ��������
	bool SetEduProg(char buf_string[]); //������� ���������
	bool SetGroup(char buf_string[]);	//�������� ������
	bool SetFacultyName(char buf_string[]);//�������� ����������

	//������ ����������...
	int GetCourse();//����� ��������
	char* GetEduProg(); //������� ���������
	char* GetGroup();	//�������� ������
	char* GetFacultyName();//�������� ����������

	//�����  ������������� ������� ������
	bool Init(int buf_course, char buf_EduProg[], char buf_Group[], char buf_FacultyName[], human buf_human);

	//����� ����� ����� ������� ������ �� �������
	bool Read();

	//����� ������ ����������� ������� ������ � �������
	void Display();
};
