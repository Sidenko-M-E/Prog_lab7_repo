using System;

namespace Prog_lab6
{
	public class Demo
	{
		static void Main(string[] args)
		{
			Console.Write("--------Fio class--------\n");
			Console.Write("------Init method-------\n");
			Fio myFio = new Fio();
			if (myFio.Init("Sidenko", "Matvey", "Evgenievich"))
				Console.Write("error\n");
			else
				myFio.Display();

			Console.Write("\n---Read method---\n");
			if (!myFio.Read())
				myFio.Display();
			else
				Console.Write("error\n");

			Console.Write("\n------Set methods-------\n");
			if ((myFio.SetSurname("Ivanov")) || (myFio.SetName("Ivan")) || (myFio.SetPatronymic("Ivanovich")))
				Console.Write("error\n");
			else
				myFio.Display();



			Console.Write("--------Human class--------\n");
			Console.Write("------init method-------\n");
			Human myHuman = new Human();
			if (myHuman.Init(1984, 45, 193, 90.87, 'M', myFio))
				Console.Write("error\n");
			else
				myHuman.Display();

			Console.Write("\n------Read method------\n");
			if (myHuman.Read())
				Console.Write("error\n");
			else
				myHuman.Display();

			Console.Write("\n------Set methods-------\n");
			if (myHuman.SetId(1999) || myHuman.SetAge(27) || myHuman.SetHeight(180) ||
				myHuman.SetWeight(80.890) || myHuman.SetGender('M'))
				Console.Write("error\n");
			else
				myHuman.Display();



			Console.Write("\n--------Student class--------\n");
			Console.Write("-------init method-------\n");
			Student myStudent = new Student();
			if (myStudent.Init(2, "Bachelor", "PI-03", "FoIT", myHuman))
				Console.Write("error\n");
			else
				myStudent.Display();

			Console.Write("\n------read method------\n");
			if (myStudent.Read())
				Console.Write("error\n");
			else
				myStudent.Display();

			Console.Write("\n------Set methods-------\n");
			if (myStudent.SetCourse(4) || myStudent.SetEduProg("Master") ||
				myStudent.SetGroup("CS-91") ||
				myStudent.SetFacultyName("FoIT"))
				Console.Write("error\n");
			else
				myStudent.Display();



			Console.Write("\n--------Teacher class--------\n");
			Console.Write("-------init method-------\n");
			Teacher myTeacher = new Teacher();
			if (myTeacher.Init(40, "Candidate of Mathematical Sciences", "FoIT", myHuman))
				Console.Write("error\n");
			else
				myTeacher.Display();

			Console.Write("\n------read method------\n");
			if (myTeacher.Read())
				Console.Write("error\n");
			else
				myTeacher.Display();

			Console.Write("\n------Set methods-------\n");
			if (myTeacher.SetWorkExp(30) || myTeacher.SetDegree("Doctor of Mathematical Sciences") || myTeacher.SetFacultyName("SMTH"))
				Console.Write("error\n");
			else
				myTeacher.Display();



			Console.Write("\n--------Faculty class--------\n");
			Console.Write("-------Init method-------\n");
			Faculty myFaculty = new Faculty();
			if (myFaculty.Init("FoIT", 180, 145, 35, 40, 20, 5, 70))
				Console.Write("error\n");
			else
				myFaculty.Display();

			Console.Write("\n------Shortcut-set methods-------\n");
			myFaculty.SetStudentsInfo(300, 270, 30);
			myFaculty.SetTeachersInfo(40, 33, 7);
			if (myFaculty.SetFacultyName("Fo****IT"))
				Console.Write("Error\n");
			else
				myFaculty.Display();

			Console.Write("\n------Read method-------\n");
			if (myFaculty.Read())
				Console.Write("error\n");
			else
				myFaculty.Display();


			Console.Write("\n----processing by methods----\n");
			Console.Write("Procent of masters on faculty: {0:f2}\n", myFaculty.GetProcentOfMasters());
			Console.Write("Procent of doctors on faculty: {0:f2}\n", myFaculty.GetProcentOfDoctors());
			Console.Write("Students to teachers quantity: {0:f2}\n", myFaculty.GetStudToTeachRatio());
			Console.ReadKey();
		}
	}
}
