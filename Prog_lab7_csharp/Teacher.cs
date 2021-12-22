using System;

namespace Prog_lab6
{
	public struct Teacher
	{
		//Attributes
		private int workExp;
		private string degree;
		private string facultyName;
		public Human humanField;


		//Properties
		public int WorkExp
		{
			get
			{
				return workExp;
			}
			set
			{
				if ((value >= 0) && (value <= 60))
					workExp = value;
			}
		}
		public string Degree 
		{
			get
			{
				string outputString = new string(degree.ToCharArray());
				return (outputString);
			}
			set
			{
				if (!string.IsNullOrEmpty(value))
				{
					string invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~`";
					char[] invalidSymbols = invalidSymbStr.ToCharArray();

					bool checkFlag = false;

					foreach (char symb in invalidSymbols)
					{
						if (value.IndexOf(symb) != (-1))
							checkFlag = true;
					}

					if (!checkFlag)
						degree = new string(value.ToCharArray());
				}
			}
		}
		public string FacultyName
		{
			get
			{
				string outputString = new string(facultyName.ToCharArray());
				return (outputString);
			}
			set
			{
				if (!string.IsNullOrEmpty(value))
				{
					string invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~` ";
					char[] invalidSymbols = invalidSymbStr.ToCharArray();

					bool checkFlag = false;

					foreach (char symb in invalidSymbols)
					{
						if (value.IndexOf(symb) != (-1))
							checkFlag = true;
					}

					if (!checkFlag)
						facultyName = new string(value.ToCharArray());
				}
			}
		}
		public Human HumanField 
		{
			get
			{
				return (humanField);
			}
			set
			{
				humanField = value;
			}
		}


		//Methods
		public bool SetWorkExp(int buf)
		{
			if (buf < 0 || buf > 60)
				return (true);
			else
			{
				workExp = buf;
				return (false);
			}
		}

		public bool SetDegree(string bufString)
		{
			if (string.IsNullOrEmpty(bufString))
				return (true);

			string invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~`";
			char[] invalidSymbols = invalidSymbStr.ToCharArray();
			foreach (char symb in invalidSymbols)
			{
				if (bufString.IndexOf(symb) != (-1))
					return (true);
			}

			degree = new string (bufString.ToCharArray());
			return (false);
		}

		public bool SetFacultyName(string bufString)
		{
			if (string.IsNullOrEmpty(bufString))
				return (true);

			string invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~` ";
			char[] invalidSymbols = invalidSymbStr.ToCharArray();
			foreach (char symb in invalidSymbols)
			{
				if (bufString.IndexOf(symb) != (-1))
					return (true);
			}

			facultyName = new string (bufString.ToCharArray());
			return (false);
		}

		public int GetWorkExp()
		{ return (workExp); }

		public string GetDegree()
		{
			string outputString = new string(degree.ToCharArray());
			return (outputString);
		}

		public string GetFacultyName()
		{
			string outputString = new string(facultyName.ToCharArray());
			return (outputString);
		}

		public static Teacher operator +(Teacher operatorTeacher, int operatorWorkExp)
		{
			return (new Teacher
			{
				WorkExp = operatorTeacher.WorkExp + operatorWorkExp,
				Degree = operatorTeacher.Degree,
				FacultyName = operatorTeacher.FacultyName,
				HumanField = operatorTeacher.HumanField
			});
		}

		public static int operator +(int operatorWorkExp, Teacher operatorTeacher)
		{
			return (operatorTeacher.workExp + operatorWorkExp);
		}

		public static Teacher operator ++(Teacher operatorTeacher)
		{
			return (new Teacher {
				WorkExp = operatorTeacher.WorkExp + 1, 
				Degree = operatorTeacher.Degree, 
				FacultyName = operatorTeacher.FacultyName, 
				HumanField = operatorTeacher.HumanField
			});
		}

		public bool Init(int bufWorkExp, string bufDegree, string bufFacultyName, Human bufHuman)
		{
			Teacher check = new Teacher();

			if (check.SetWorkExp(bufWorkExp) || check.SetDegree(bufDegree) || check.SetFacultyName(bufFacultyName))
				return (true);
			else
			{
				this.SetWorkExp(bufWorkExp);
				this.SetDegree(bufDegree);
				this.SetFacultyName(bufFacultyName);
				this.humanField.Init(bufHuman.GetId(), bufHuman.GetAge(),
				bufHuman.GetHeight(), bufHuman.GetWeight(), bufHuman.GetGender(), bufHuman.fioField);
				return (false);
			}
		}

		public bool Read()
		{
			Teacher check = new Teacher();
			int bufInt;

			Console.Write("Enter scientific degree:\n");
			if (check.SetDegree(Console.ReadLine()))
				return (true);


			Console.Write("Enter faculty name:\n");
			if (check.SetFacultyName(Console.ReadLine()))
				return (true);


			Console.Write("Enter working experience:\n");
			if (!int.TryParse(Console.ReadLine(), out bufInt))
				return (true);
			if (check.SetWorkExp(bufInt))
				return (true);


			if (check.humanField.Read())
				return (true);


			this.Init(check.GetWorkExp(), check.GetDegree(),
			check.GetFacultyName(), check.humanField);
			return (false);

		}

		public void Display()
		{
			Console.Write("working experience: {0} years\n", workExp);
			Console.Write("scientific degree: {0}\n", degree);
			Console.Write("faculty name: {0}\n", facultyName);
			humanField.Display();
		}
	}
}
