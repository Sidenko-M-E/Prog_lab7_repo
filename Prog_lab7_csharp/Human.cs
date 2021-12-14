using System;
using System.Globalization;

namespace Prog_lab6
{
    public class Human
    {
		//Attributes
		private int id;
		private int age;
		private int height;
		private double weight;
		private char gender;
		public Fio fioField = new Fio();


		//Properties
		public int Id
		{
			get
			{
				return id;
			}
			set
			{
				if ((value >= 0) && (value <= 9999))
					id = value;
			}
		}
		public int Age 
		{
			get
			{
				return age;
			}
			set
			{
				if ((value >= 0) && (value <= 200))
					age = value;
			}
		}
		public int Height
		{
			get
			{
				return height;
			}
			set
			{
				if ((value >= 40) && (value <= 300))
					height = value;
			}
		}
		public double Weight
		{
			get
			{
				return weight;
			}
			set
			{
				value = Math.Round(value, 1, MidpointRounding.AwayFromZero);
				if ((value >= 0) && (value <= 650))
					weight = value;
			}
		}
		public char Gender
        {
			get
			{
				return gender;
			}
			set
			{
				if (value == 'M' || value == 'F')
					gender = value;
			}
		}
		public Fio FioField 
		{
			get
			{
				return (fioField);
			}
			set
			{
				fioField = value;
			}
		} 


		//Methods
		public bool SetId(int buf)
		{
			if (buf < 0 || buf > 9999)
				return (true);
			else
			{
				id = buf;
				return (false);
			}
		}

		public bool SetAge(int buf)
		{
			if (buf < 0 || buf > 200)
				return (true);
			else
			{
				age = buf;
				return (false);
			}
		}

		public bool SetHeight(int buf)
		{
			if (buf < 40 || buf > 300)
				return (true);
			else
			{
				height = buf;
				return (false);
			}
		}

		public bool SetWeight(double buf)
		{
			//round *.* format to *.1 format 
			buf = Math.Round(buf, 1, MidpointRounding.AwayFromZero);
			if (buf < 0 || buf > 650)
				return (true);
			else
			{
				weight = buf;
				return (false);
			}
		}

		public bool SetGender(char buf)
		{
			if (buf == 'M' || buf == 'F')
			{
				gender = buf;
				return (false);
			}
			else
				return (true);
		}

		public int GetId()
		{ return (id); }

		public int GetAge()
		{ return (age); }

		public int GetHeight()
		{ return (height); }

		public double GetWeight()
		{ return (weight); }

		public char GetGender()
		{ return (gender); }

		public bool Init(int bufId, int bufAge, int bufHeight, double bufWeight, char bufGender, Fio bufFio)
		{
			Human check = new Human();

			if (check.SetId(bufId) || check.SetAge(bufAge) || check.SetHeight(bufHeight) ||
				check.SetWeight(bufWeight) || check.SetGender(bufGender))
				return (true);
			else
			{
				this.SetId(check.GetId());
				this.SetAge(check.GetAge());
				this.SetHeight(check.GetHeight());
				this.SetWeight(check.GetWeight());
				this.SetGender(check.GetGender());
				this.fioField.Init(bufFio.GetSurname(), bufFio.GetName(), bufFio.GetPatronymic());
				return (false);
			}
		}

		public bool Read()
		{
			Human check = new Human();
			int bufInt;
			double bufDouble;
			char bufChar;

			Console.Write("Enter id:\n");
			if (!int.TryParse(Console.ReadLine(), out bufInt))
				return (true);
			if (check.SetId(bufInt))
				return (true);


			Console.Write("Enter age:\n");
			if (!int.TryParse(Console.ReadLine(), out bufInt))
				return (true);
			if (check.SetAge(bufInt))
				return (true);


			Console.Write("Enter height:\n");
			if (!int.TryParse(Console.ReadLine(), out bufInt))
				return (true);
			if (check.SetHeight(bufInt))
				return (true);


			Console.Write("Enter weight:\n");
			if (!double.TryParse(Console.ReadLine(), NumberStyles.AllowDecimalPoint, CultureInfo.CreateSpecificCulture("fr-FR"), out bufDouble))
				return (true);
			if (check.SetWeight(bufDouble))
				return (true);


			Console.Write("Enter gender:\n");
			if (!char.TryParse(Console.ReadLine(), out bufChar))
				return (true);
			if (check.SetGender(bufChar))
				return (true);


			if (check.fioField.Read())
				return (true);


			this.Init(check.GetId(), check.GetAge(), check.GetHeight(), check.GetWeight(), check.GetGender(), check.fioField);
			return (false);
		}

		public void Display()
		{
			Console.Write("id: {0}\n", id);
			Console.Write("age: {0}\n", age);
			Console.Write("height: {0}\n", height);
			Console.Write("weight: {0:f1}\n", weight);
			Console.Write("gender: {0}\n", gender);
			fioField.Display();
		}
	}
}
