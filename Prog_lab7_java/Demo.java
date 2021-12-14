package Prog_lab7_java;

import java.util.Random;

public class Demo{
	public static void main(String[] args)
	{
		/*
		System.out.print("--------Fio class--------\n");
		System.out.print("------init method-------\n");
		 */
		Fio myFio = new Fio();
	
		if(myFio.init("Sidenko", "Matvey", "Evgenievich"))
			System.out.print("error\n");
		else
			myFio.display();

		/*
		System.out.print("\n---read method---\n");
		if (!myFio.read())
			myFio.display();
		else
			System.out.print("error\n");

		System.out.print("\n------Set methods-------\n");
		if ((myFio.setSurname("Ivanov"))||(myFio.setName("Ivan"))||(myFio.setPatronymic("Ivanovich")))
			System.out.print("error\n");
		else
			myFio.display();
		*/


		/*
		System.out.print("--------Human class--------\n");
		System.out.print("------init method-------\n");
		 */

		Human myHuman = new Human();
		if(myHuman.init(1984, 45, 193, 90.87, 'M', myFio))
			System.out.print("error\n");
		else
			myHuman.display();

		/*
		System.out.print("\n------read method------\n");
		if (myHuman.read())
			System.out.print("error\n");
		else
			myHuman.display();

		System.out.print("\n------set methods-------\n");
		if (myHuman.setId(1999) || myHuman.setAge(27) || myHuman.setHeight(180) ||
			myHuman.setWeight(80.890) || myHuman.setGender('M'))
			System.out.print("error\n");
		else
			myHuman.display();
		*/
		System.out.print("\n----BodyMassIndex calculating----\n");
		System.out.printf("BMI: %d\n", myHuman.getBodyMassIndex());


/*
		System.out.print("\n--------Student class--------\n");
		System.out.print("-------init method-------\n");
		Student myStudent = new Student();
		if (myStudent.init(2, "Bachelor", "PI-03", "FoIT", myHuman))
			System.out.print("error\n");
		else 
			myStudent.display();

		System.out.print("\n------read method------\n");
		if (myStudent.read())
			System.out.print("error\n");
		else
			myStudent.display();

		System.out.print("\n------Set methods-------\n");
		if (myStudent.setCourse(4) || myStudent.setEduProg("Master") || 
			myStudent.setGroup("CS-91") ||
			myStudent.setFacultyName("FoIT"))
			System.out.print("error\n");
		else
			myStudent.display();
		


		System.out.print("\n--------Teacher class--------\n");
		System.out.print("-------init method-------\n");
		Teacher myTeacher = new Teacher();
		if (myTeacher.init(40, "Candidate of Mathematical Sciences", "FoIT", myHuman))
			System.out.print("error\n");
		else
			myTeacher.display();

		System.out.print("\n------read method------\n");
		if (myTeacher.read())
			System.out.print("error\n");
		else
			myTeacher.display();

		System.out.print("\n------Set methods-------\n");
		if (myTeacher.setWorkExp(30) || myTeacher.setDegree("Doctor of Mathematical Sciences") || myTeacher.setFacultyName("SMTH"))
			System.out.print("error\n");
		else
			myTeacher.display();

		*/



		System.out.print("\n--------Faculty class--------\n");
		System.out.print("-------init method-------\n");
		Faculty myFaculty = new Faculty();
		if (myFaculty.init("FoIT", 180, 145, 35, 40, 20, 5, 70))
			System.out.print("error\n");
		else
			myFaculty.display();

		/*
		System.out.print("\n------Shortcut-set methods-------\n");
		myFaculty.setStudentsInfo(300, 270, 30);
		myFaculty.setTeachersInfo(40, 33, 7);
		if (myFaculty.setFacultyName("Fo****IT"))
			System.out.print("Error\n");
		else
			myFaculty.display();

		System.out.print("\n------read method-------\n");
		if(myFaculty.read())
			System.out.print("error\n");
		else
			myFaculty.display();
	
		System.out.print("\n----processing by methods----\n");
		System.out.printf("Percent of masters on faculty: %.2f\n", myFaculty.getPercentOfMasters());
		System.out.printf("Percent of doctors on faculty: %.2f\n", myFaculty.getPercentOfDoctors());
		System.out.printf("Students to teachers quantity: %.2f\n", myFaculty.getStudToTeachRatio());

		*/
		System.out.print("\n------array of objects------\n");
		int sumOfStudents = 0;
		Random rnd = new Random();
		rnd.setSeed(251);

		Faculty[] objArray = new Faculty[3];
		for (int i = 0; i < objArray.length; i++)
		{
			objArray[i] = new Faculty();
			objArray[i].init("smth", rnd.nextInt(500),
					rnd.nextInt(450), rnd.nextInt(50),
					rnd.nextInt(100), rnd.nextInt(80),
					rnd.nextInt(20), rnd.nextInt(50));
			sumOfStudents += objArray[i].getQuantityOfStudents();
			objArray[i].display();
		}
		System.out.printf("\nTotal quantity of students on all faculties: %d\n", sumOfStudents);
		System.out.print("\nLet's compare first and second faculties to find the one...\n");
		System.out.print("...that have the largest number of candidates on it.\n");
		System.out.print("And the answer is:\n");
		objArray[0].getWithMoreCandidates(objArray[1]).display();

	}
}