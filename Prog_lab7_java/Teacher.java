package Prog_lab5;

import java.util.*;

public class Teacher 
{
	//Attributes
	private int workExp;
	private String degree;
	private String facultyName;
	public Human humanField = new Human();

	//Methods
	public boolean setWorkExp(int buf)
	{
		if (buf < 0 || buf > 60)
		return (true);
		else
		{
			workExp = buf;
			return (false);
		}
	}

	public boolean setDegree(String bufString)
	{
		if (bufString.isEmpty()) 
			return (true);
		
		String invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~`";
		char[] invalidSymbols = invalidSymbStr.toCharArray();
		for (char symb : invalidSymbols) 
		{
			if(bufString.indexOf(symb) != (-1))
				return (true);
		}

		degree = degree.copyValueOf(bufString.toCharArray());
		return (false);
	}

	public boolean setFacultyName(String bufString)
	{
		if (bufString.isEmpty()) 
			return (true);
		
		String invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~` ";
		char[] invalidSymbols = invalidSymbStr.toCharArray();
		for (char symb : invalidSymbols) 
		{
			if(bufString.indexOf(symb) != (-1))
				return (true);
		}

		facultyName = facultyName.copyValueOf(bufString.toCharArray());
		return (false);
	}

	public int getWorkExp()
	{
		return (workExp);
	}

	public String getDegree()
	{
		return (String.copyValueOf(degree.toCharArray()));
	}

	public String getFacultyName()
	{
		return (String.copyValueOf(facultyName.toCharArray()));
	}
	
	public boolean init(int bufWorkExp, String bufDegree, String bufFacultyName, Human bufHuman)
	{
		Teacher check = new Teacher();

		if (check.setWorkExp(bufWorkExp) || check.setDegree(bufDegree) || check.setFacultyName(bufFacultyName))
			return (true);
		else
		{
			this.setWorkExp(bufWorkExp);
			this.setDegree(bufDegree);
			this.setFacultyName(bufFacultyName);
			this.humanField.init(bufHuman.getId(), bufHuman.getAge(),
			bufHuman.getHeight(), bufHuman.getWeight(),bufHuman.getGender(), bufHuman.fioField);
			return (false);
		}
	}
	
	public boolean read()
	{
		Teacher check = new Teacher();
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter scientific degree:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setDegree(scanner.nextLine()))
			return (true);


		System.out.print("Enter faculty name:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setFacultyName(scanner.nextLine()))
			return (true);


		System.out.print("Enter working experience:\n");
		if (!scanner.hasNextInt())
			return (true);
		if (check.setWorkExp(scanner.nextInt()))
			return (true);


		if (check.humanField.read())
			return(true);


		this.init(check.getWorkExp(), check.getDegree(),
				check.getFacultyName(), check.humanField);
		return(false);
	}

	public void display()
	{
		System.out.printf("working experience: %d years\n", workExp);
		System.out.printf("scientific degree: %s\n",degree);
		System.out.printf("faculty name: %s\n", facultyName);
		humanField.display();
	}
}