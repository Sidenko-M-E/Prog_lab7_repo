#include "human.h"

class teacher {
private:
	int WorkExp;//������� ����
	char Degree[40];//������ �������
	char FacultyName[30];//�������� ����������

public:
	human thehuman; //������������ "human"

	//������ ���������...
	bool SetWorkExp(int buf);//�������� �����
	bool SetDegree(char buf_string[]);//������ �������
	bool SetFacultyName(char buf_string[]);//�������� ����������

	//������ ����������...
	int GetWorkExp();//�������� �����
	char* GetDegree();//������ �������
	char* GetFacultyName();//�������� ����������

	//�����  ������������� ������� ������
	bool Init(int buf_WorkExp, char buf_Degree[], char buf_FacultyName[], human buf_human);

	//����� ����� ����� ������� ������ �� �������
	bool Read();

	//����� ������ ����������� ������� ������ � �������
	void Display();
};
