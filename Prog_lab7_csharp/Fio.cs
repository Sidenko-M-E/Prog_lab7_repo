using System;

namespace Prog_lab6
{
	public class Fio
	{
		//Attributes
		private string surname;
		private string name;
		private string patronymic;


		//Properties
		public string Surname
		{
			get
			{
				string outputString = new string(surname.ToCharArray());
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
						surname = new string(value.ToCharArray());
				}
			}
		}
		public string Name
		{
			get
			{
				string outputString = new string(name.ToCharArray());
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
						name = new string(value.ToCharArray());
				}
			}
		}
		public string Patronymic
		{
			get
			{
				string outputString = new string(patronymic.ToCharArray());
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
						patronymic = new string(value.ToCharArray());
				}
			}
		}


		//Methods
		public bool SetSurname(string bufString)
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

			surname = new string(bufString.ToCharArray());
			return (false);
		}

		public bool SetName(string bufString)
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

			name = new string(bufString.ToCharArray());
			return (false);
		}

		public bool SetPatronymic(string bufString)
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

			patronymic = new string(bufString.ToCharArray());
			return (false);
		}

		public string GetSurname()
		{
			string outputString = new string(surname.ToCharArray());
			return (outputString);
		}

		public string GetName()
		{
			string outputString = new string(name.ToCharArray());
			return (outputString);
		}

		public string GetPatronymic()
		{
			string outputString = new string(patronymic.ToCharArray());
			return (outputString);
		}

		public bool Init(string bufSurname, string bufName, string bufPatronymic)
		{
			Fio check = new Fio();

			if (check.SetSurname(bufSurname) || check.SetName(bufName) || check.SetPatronymic(bufPatronymic))
				return (true);
			else
			{
				this.SetSurname(bufSurname);
				this.SetName(bufName);
				this.SetPatronymic(bufPatronymic);
				return (false);
			}
		}

		public bool Read()
		{
			Fio check = new Fio();

			Console.Write("Enter surname:\n");
			if (check.SetSurname(Console.ReadLine()))
				return (true);


			Console.Write("Enter name:\n");
			if (check.SetName(Console.ReadLine()))
				return (true);


			Console.Write("Enter patronymic:\n");
			if (check.SetPatronymic(Console.ReadLine()))
				return (true);


			this.SetSurname(check.GetSurname());
			this.SetName(check.GetName());
			this.SetPatronymic(check.GetPatronymic());
			return (false);
		}

		public void Display()
		{
			Console.Write("FIO: {0} {1} {2}\n", surname, name, patronymic);
		}
	}
}

