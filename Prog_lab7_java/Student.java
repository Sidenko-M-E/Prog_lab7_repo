package Prog_lab5;

import java.util.*;

public class Student
{
	//Attributes
	private int course;  
	private	String eduProg;
	private String group;
	private String facultyName;
	public Human humanField = new Human();

	//Methods
	public boolean setCourse(int buf)
	{
		if (buf < 0 || buf > 6)
			return (true);
		else
		{
			course = buf;
			return (false);
		}
	}

	public boolean setEduProg(String bufString)
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

		eduProg = eduProg.copyValueOf(bufString.toCharArray());
		return (false);
	}

	public boolean setGroup(String bufString)
	{
		if (bufString.isEmpty()) 
			return (true);
		
		String invalidSymbStr = "!@#$%^&*()_+=\";:?*,./'][{}<>~` ";
		char[] invalidSymbols = invalidSymbStr.toCharArray();
		for (char symb : invalidSymbols) 
		{
			if(bufString.indexOf(symb) != (-1))
				return (true);
		}

		group = group.copyValueOf(bufString.toCharArray());
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

	public int getCourse()
	{
		return(course);
	}

	public String getEduProg()
	{
		return (String.copyValueOf(eduProg.toCharArray()));
	}

	public String getGroup()
	{
		return (String.copyValueOf(group.toCharArray()));
	}

	public String getFacultyName()
	{
		return (String.copyValueOf(facultyName.toCharArray()));
	}

	public boolean init(int bufCourse, String bufEduProg, String bufGroup, String bufFacultyName, Human bufHuman)
	{
		Student check = new Student();

		if (check.setCourse(bufCourse) || check.setEduProg(bufEduProg) || check.setGroup(bufGroup) ||
			check.setFacultyName(bufFacultyName))
			return (true);
		else
		{
			this.setCourse(bufCourse);
			this.setEduProg(bufEduProg);
			this.setGroup(bufGroup);
			this.setFacultyName(bufFacultyName);
			this.humanField.init(bufHuman.getId(), bufHuman.getAge(),
			bufHuman.getHeight(), bufHuman.getWeight(),bufHuman.getGender(), bufHuman.fioField);
			return (false);
		}
	}

	public boolean read()
	{
		Student check = new Student();
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter education programme:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setEduProg(scanner.nextLine()))
			return (true);


		System.out.print("Enter group:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setGroup(scanner.nextLine()))
			return (true);


		System.out.print("Enter faculty name:\n");
		if (!scanner.hasNextLine())
			return (true);
		if (check.setFacultyName(scanner.nextLine()))
			return (true);


		System.out.print("Enter course:\n");
		if (!scanner.hasNextInt())
			return (true);
		if (check.setCourse(scanner.nextInt()))
			return (true);


		if (check.humanField.read())
			return(true);


		this.init(check.getCourse(), check.getEduProg(), check.getGroup(),
				check.getFacultyName(), check.humanField);
		return(false);
	}

	void display()
	{
		System.out.printf("course: %d\n", course);
		System.out.printf("direction of preparation: %s\n", eduProg);
		System.out.printf("group: %s\n", group);
		System.out.printf("faculty name: %s\n", facultyName);
		humanField.display();
	}
}