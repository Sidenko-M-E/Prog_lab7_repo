class faculty
{
private:
	char FacultyName[30];//�������� ����������
	int QuantityOfStudents;	 //���-�� �������� �� ����������
	int QuantityOfBachelors; //���-�� ����������� �� ������������
	int QuantityOfMasters;	 //���-�� ����������� � ������������

	int QuantityOfTeachers;	  //���-�� ��������������
	int QuantityOfCandidates; //���-�� ���������� ����
	int QuantityOfDoctors;    //���-�� �������� ����
	
	int QuantityOfDisciplines;//���-�� ������������� ���������

public:
	//������ ���������...
	bool SetFacultyName(char buf_string[]);//�������� ����������
	bool SetQuantityOfStudents(int buf);//���-�� �������� �� ����������
	bool SetQuantityOfBachelors(int buf);//���-�� ����������� �� ������������
	bool SetQuantityOfMasters(int buf); //���-�� ����������� � ������������

	bool SetQuantityOfTeachers(int buf);//���-�� ��������������
	bool SetQuantityOfCandidates(int buf);//���-�� ���������� ����
	bool SetQuantityOfDoctors(int buf);//���-�� �������� ����

	bool SetQuantityOfDisciplines(int buf);//���-�� ������������� ���������

	bool SetStudentsInfo(int all_quan, int bach_quan, int mast_quan);//���������� � ���������
	
	bool SetTeachersInfo(int all_quan, int cand_quan, int doct_quan);//���������� � ��������������

	//������ ����������...
	char* GetFacultyName();//�������� ����������
	int GetQuantityOfStudents();//���-�� �������� �� ����������
	int GetQuantityOfBachelors();//���-�� ����������� �� ������������
	int GetQuantityOfMasters(); //���-�� ����������� � ������������

	int GetQuantityOfTeachers();//���-�� ��������������
	int GetQuantityOfCandidates();//���-�� ���������� ����
	int GetQuantityOfDoctors();//���-�� �������� ����

	int GetQuantityOfDisciplines();//���-�� ������������� ���������

	//����� �������� ����������� ���-�� ��������� ����� ��������
	double ProcentOfMasters();

	//����� �������� ����������� ���-�� �������� ���� ����� ��������������
	double ProcentOfDoctors();

	//����� �������� ���-�� ���������, ������������ �� ������ �������������
	double ProcOfStudToTeach();

	//�����  ������������� ������� ������
	bool Init(char buf_FacultyName[], int stud_quan, int bach_quan, int mast_quan, int teac_quan, int cand_quan, int doct_quan, int disc_quan);

	//����� ����� ����� ������� ������ �� �������
	bool Read();

	//����� ������ ����������� ������� ������ � �������
	void Display();
};
