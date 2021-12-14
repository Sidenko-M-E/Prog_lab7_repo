﻿using System;

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

			Console.Write("\n------set properties demo-------\n");
			myFio.Surname = "Sidorov";
			myFio.Name = "Oleg";
			myFio.Patronymic = "Litvinovich";
			myFio.Display();

			Console.Write("\n------get properties demo-------\n");
			Fio demoFio = new Fio();
			demoFio.Init(myFio.Surname, myFio.Name, myFio.Patronymic);
			demoFio.Display();




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

			Console.Write("\n------set properties demo-------\n");
			myHuman.Id = 2000;
			myHuman.Age = 40;
			myHuman.Height = 190;
			myHuman.Weight = 86.190;
			myHuman.Gender = 'M';
			myHuman.FioField = demoFio;
			myHuman.Display();

			Console.Write("\n------get properties demo-------\n");
			Human demoHuman = new Human();
			demoHuman.Init(myHuman.Id, myHuman.Age, myHuman.Height, myHuman.Weight, myHuman.Gender, myHuman.FioField);
			demoHuman.Display();


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

			Console.Write("\n------set properties demo-------\n");
			myStudent.Course = 1;
			myStudent.EduProg = "Bachelor";
			myStudent.Group = "WS-34";
			myStudent.FacultyName = "FoHS";
			myStudent.HumanField = demoHuman;
			myStudent.Display();

			Console.Write("\n------get properties demo-------\n");
			Student demoStudent = new Student();
			demoStudent.Init(myStudent.Course, myStudent.EduProg, myStudent.Group, myStudent.FacultyName, myStudent.HumanField);
			demoStudent.Display();


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

			Console.Write("\n------set properties demo-------\n");
			myStudent.Course = 1;
			myStudent.EduProg = "Bachelor";
			myStudent.Group = "WS-34";
			myStudent.FacultyName = "FoHS";
			myStudent.HumanField = demoHuman;
			myStudent.Display();

			Console.Write("\n------get properties demo-------\n");
			Student demoStudent = new Student();
			demoStudent.Init(myStudent.Course, myStudent.EduProg, myStudent.Group, myStudent.FacultyName, myStudent.HumanField);
			demoStudent.Display();


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


			Console.Write("\n------array of objects------\n");
			int sumOfStudents = 0;
			Random rnd = new Random();

			Faculty[] objArray = new Faculty[3];
			for (int i = 0; i < objArray.Length; i++)
			{
				objArray[i] = new Faculty();
				objArray[i].Init("smth", rnd.Next(500),
						rnd.Next(450), rnd.Next(50),
						rnd.Next(100), rnd.Next(80),
						rnd.Next(20), rnd.Next(50));
				sumOfStudents += objArray[i].GetQuantityOfStudents();
				objArray[i].Display();
			}
			Console.Write("\nTotal quantity of students on all faculties: {0}\n", sumOfStudents);
			Console.Write("\nLet's compare first and second faculties to find the one...\n");
			Console.Write("...that have the largest number of candidates on it.\n");
			Console.Write("And the answer is:\n");
			objArray[0].GetWithMoreCandidates(objArray[1]).Display();

			Console.ReadKey();
		}
	}
}
