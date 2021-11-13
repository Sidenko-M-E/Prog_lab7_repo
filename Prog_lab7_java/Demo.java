package Prog_lab5;

public class Demo{
	public static void main(String[] args)
	{
		System.out.printf("--------Fio class--------\n");
		System.out.printf("------init method-------\n");
		Fio myFio = new Fio();
	
		if(myFio.init("Sidenko", "Matvey", "Evgenievich"))
			System.out.printf("error\n");
		else
			myFio.display();

		System.out.printf("\n---read method---\n");
		if (!myFio.read())
			myFio.display();
		else
			System.out.printf("error\n");

		System.out.printf("\n------Set methods-------\n");
		if ((myFio.setSurname("Ivanov"))||(myFio.setName("Ivan"))||(myFio.setPatronymic("Ivanovich")))
			System.out.printf("error\n");
		else
			myFio.display();



		System.out.printf("--------Human class--------\n");
		System.out.printf("------init method-------\n");
		Human myHuman = new Human();
		if(myHuman.init(1984, 45, 193, 90.87, 'M', myFio))
			System.out.printf("error\n");
		else
			myHuman.display();

		System.out.printf("\n------read method------\n");
		if (myHuman.read())
			System.out.printf("error\n");
		else
			myHuman.display();

		System.out.printf("\n------set methods-------\n");
		if (myHuman.setId(1999) || myHuman.setAge(27) || myHuman.setHeight(180) ||
			myHuman.setWeight(80.890) || myHuman.setGender('M'))
			System.out.printf("error\n");
		else
			myHuman.display();



		System.out.printf("\n--------Student class--------\n");
		System.out.printf("-------init method-------\n");
		Student myStudent = new Student();
		if (myStudent.init(2, "Bachelor", "PI-03", "FoIT", myHuman))
			System.out.printf("error\n");
		else 
			myStudent.display();

		System.out.printf("\n------read method------\n");
		if (myStudent.read())
			System.out.printf("error\n");
		else
			myStudent.display();

		System.out.printf("\n------Set methods-------\n");
		if (myStudent.setCourse(4) || myStudent.setEduProg("Master") || 
			myStudent.setGroup("CS-91") ||
			myStudent.setFacultyName("FoIT"))
			System.out.printf("error\n");
		else
			myStudent.display();
		


		System.out.printf("\n--------Teacher class--------\n");
		System.out.printf("-------init method-------\n");
		Teacher myTeacher = new Teacher();
		if (myTeacher.init(40, "Candidate of Mathematical Sciences", "FoIT", myHuman))
			System.out.printf("error\n");
		else
			myTeacher.display();

		System.out.printf("\n------read method------\n");
		if (myTeacher.read())
			System.out.printf("error\n");
		else
			myTeacher.display();

		System.out.printf("\n------Set methods-------\n");
		if (myTeacher.setWorkExp(30) || myTeacher.setDegree("Doctor of Mathematical Sciences") || myTeacher.setFacultyName("SMTH"))
			System.out.printf("error\n");
		else
			myTeacher.display();



		System.out.printf("\n--------Faculty class--------\n");
		System.out.printf("-------init method-------\n");
		Faculty myFaculty = new Faculty();
		if (myFaculty.Init("FoIT", 180, 145, 35, 40, 20, 5, 70))
			System.out.printf("error\n");
		else
			myFaculty.display();

		System.out.printf("\n------Shortcut-set methods-------\n");
		myFaculty.setStudentsInfo(300, 270, 30);
		myFaculty.setTeachersInfo(40, 33, 7);
		if (myFaculty.setFacultyName("Fo****IT"))
			System.out.printf("Error\n");
		else
			myFaculty.display();

		System.out.printf("\n------read method-------\n");
		if(myFaculty.read())
			System.out.printf("error\n");
		else
			myFaculty.display();
	
		System.out.printf("\n----processing by methods----\n");
		System.out.printf("Procent of masters on faculty: %.2f\n", myFaculty.getProcentOfMasters());
		System.out.printf("Procent of doctors on faculty: %.2f\n", myFaculty.getProcentOfDoctors());
		System.out.printf("Students to teachers quantity: %.2f\n", myFaculty.getStudToTeachRatio());
	}
}