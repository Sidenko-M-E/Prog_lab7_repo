class faculty
{
private:
	char FacultyName[30];//название факультета
	int QuantityOfStudents;	 //кол-во студетов на факультете
	int QuantityOfBachelors; //кол-во обучающихся на бакалавриате
	int QuantityOfMasters;	 //кол-во обучающихся в магистратуре

	int QuantityOfTeachers;	  //кол-во преподавателей
	int QuantityOfCandidates; //кол-во кандидатов наук
	int QuantityOfDoctors;    //кол-во докторов наук
	
	int QuantityOfDisciplines;//кол-во преподаваемых дисциплин

public:
	//Методы установки...
	bool SetFacultyName(char buf_string[]);//названия факультета
	bool SetQuantityOfStudents(int buf);//кол-ва студетов на факультете
	bool SetQuantityOfBachelors(int buf);//кол-ва обучающихся на бакалавриате
	bool SetQuantityOfMasters(int buf); //кол-ва обучающихся в магистратуре

	bool SetQuantityOfTeachers(int buf);//кол-ва преподавателей
	bool SetQuantityOfCandidates(int buf);//кол-ва кандидатов наук
	bool SetQuantityOfDoctors(int buf);//кол-ва докторов наук

	bool SetQuantityOfDisciplines(int buf);//кол-ва преподаваемых дисциплин

	bool SetStudentsInfo(int all_quan, int bach_quan, int mast_quan);//информации о студентах
	
	bool SetTeachersInfo(int all_quan, int cand_quan, int doct_quan);//информации о преподавателях

	//Методы извлечения...
	char* GetFacultyName();//названия факультета
	int GetQuantityOfStudents();//кол-ва студетов на факультете
	int GetQuantityOfBachelors();//кол-ва обучающихся на бакалавриате
	int GetQuantityOfMasters(); //кол-ва обучающихся в магистратуре

	int GetQuantityOfTeachers();//кол-ва преподавателей
	int GetQuantityOfCandidates();//кол-ва кандидатов наук
	int GetQuantityOfDoctors();//кол-ва докторов наук

	int GetQuantityOfDisciplines();//кол-ва преподаваемых дисциплин

	//Метод подсчёта процентного кол-ва магистров среди учащихся
	double ProcentOfMasters();

	//Метод подсчёта процентного кол-ва докторов наук среди преподавателей
	double ProcentOfDoctors();

	//Метод подсчёта кол-ва студентов, приходящихся на одного преподавателя
	double ProcOfStudToTeach();

	//Метод  инициализации объекта класса
	bool Init(char buf_FacultyName[], int stud_quan, int bach_quan, int mast_quan, int teac_quan, int cand_quan, int doct_quan, int disc_quan);

	//Метод ввода полей объекта класса из консоли
	bool Read();

	//Метод вывода содержимого объекта класса в консоль
	void Display();
};
