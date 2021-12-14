using System;

namespace Prog_lab6 
{
	public class Teacher
	{
		//Attributes
		private int workExp;
		private string degree;
		private string facultyName;
		public Human humanField = new Human();

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
