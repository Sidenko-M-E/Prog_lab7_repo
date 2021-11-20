package Prog_lab5;

import java.util.*;

public class Fio
{
	//Attributes
	private String surname;
	private String name;
	private String patronymic;

	//Methods
	public boolean setSurname(String bufString)
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

		surname = surname.copyValueOf(bufString.toCharArray());
		return (false);
	}

	public boolean setName(String bufString)
	{
		if (bufString.isEmpty())
			return (true);
		
		String invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~` ";
		char[] invalidSymbols = invalidSymbStr.toCharArray();
		for (char symb : invalidSymbols)
		{
			if (bufString.indexOf(symb) != (-1))
				return (true);
		}

		name = name.copyValueOf(bufString.toCharArray());
		return (false);
	}

	public boolean setPatronymic(String bufString)
	{
		if (bufString.isEmpty())
			return (true);
			
		String invalidSymbStr = "!@#$%^&*()_+1234567890-=\";:?*,./'][{}<>~` ";
		char[] invalidSymbols = invalidSymbStr.toCharArray();
		for (char symb : invalidSymbols)
		{
			if (bufString.indexOf(symb) != (-1))
			return (true);
		}

		patronymic = patronymic.copyValueOf(bufString.toCharArray());
		return (false);
	}

	public String getSurname()
	{
		return (String.copyValueOf(surname.toCharArray()));
	}

	public String getName()
	{
		return (String.copyValueOf(name.toCharArray()));
	}

	public String getPatronymic()
	{
		return (String.copyValueOf(patronymic.toCharArray()));
	}

	public boolean init(String bufSurname, String bufName, String bufPatronymic)
	{
		Fio check = new Fio();

		if (check.setSurname(bufSurname) || check.setName(bufName) || check.setPatronymic(bufPatronymic))
			return (true);
		else
		{
			this.setSurname(bufSurname);
			this.setName(bufName);
			this.setPatronymic(bufPatronymic);
			return (false);
		}
	}

	public boolean read()
	{
		Fio check = new Fio();
		Scanner scanner = new Scanner(System.in);


		System.out.print("Enter surname:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setSurname(scanner.nextLine()))
			return (true);


		System.out.print("Enter name:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setName(scanner.nextLine()))
			return (true);


		System.out.print("Enter patronymic:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setPatronymic(scanner.nextLine()))
			return (true);


		this.init(check.getSurname(), check.getName(), check.getPatronymic());
		return (false);
	}

	public void display()
	{
		System.out.printf("FIO: %s %s %s\n", surname, name, patronymic);
	}
}