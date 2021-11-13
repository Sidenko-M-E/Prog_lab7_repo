package Prog_lab5;

import java.util.*;
import java.lang.Math.*;

public class Faculty
{
	//Attributes
	private String facultyName;
	private int quantityOfStudents;
	private int quantityOfBachelors;
	private int quantityOfMasters;
	private int quantityOfTeachers; 
	private int quantityOfCandidates;
	private int quantityOfDoctors;
	private int quantityOfDisciplines;


	//Set methods
	public boolean setFacultyName(String bufString)
	{
		if (bufString.isEmpty()) {
			return (true);
		}

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

	public boolean setQuantityOfStudents(int buf)
	{
		if (buf < 0 || buf > 1000)
			return (true);
		else
		{
			quantityOfStudents = buf;
			return (false);
		}
	}

	public boolean setQuantityOfBachelors(int buf)
	{
		if (buf < 0 || buf > 1000)
		return (true);
		else
		{
			quantityOfBachelors = buf;
			return (false);
		}
	}

	public boolean setQuantityOfMasters(int buf)
	{
		if (buf < 0 || buf > 1000)
		return (true);
		else
		{
			quantityOfMasters = buf;
			return (false);
		}
	}

	public boolean setQuantityOfTeachers(int buf)
	{
		if (buf < 0 || buf > 100)
		return (true);
		else
		{
			quantityOfTeachers = buf;
			return (false);
		}
	}

	public boolean setQuantityOfCandidates(int buf)
	{
		if (buf < 0 || buf > 100)
		return (true);
		else
		{
			quantityOfCandidates = buf;
			return (false);
		}
	}

	public boolean setQuantityOfDoctors(int buf)
	{
		if (buf < 0 || buf > 100)
		return (true);
		else
		{
			quantityOfDoctors = buf;
			return (false);
		}
	}

	public boolean setQuantityOfDisciplines(int buf)
	{
		if (buf < 0 || buf > 100)
		return (true);
		else
		{
			quantityOfDisciplines = buf;
			return (false);
		}
	}

	public boolean setStudentsInfo(int allQuantity, int bachelorsQuantity, int mastersQuantity)
	{
		if (allQuantity < 0 || allQuantity > 1000 || bachelorsQuantity < 0 || bachelorsQuantity > 1000 || mastersQuantity < 0 || mastersQuantity > 1000)
			return (true);
		else
		{
			quantityOfStudents = allQuantity;
			quantityOfBachelors = bachelorsQuantity;
			quantityOfMasters = mastersQuantity;
			return (false);
		}
	}	

	public boolean setTeachersInfo(int allQuantity, int candidatesQuantity, int doctorsQuantity)
	{
		if (allQuantity < 0 || allQuantity > 100 || candidatesQuantity < 0 || candidatesQuantity > 100 || doctorsQuantity < 0 || doctorsQuantity > 100)
			return (true);
		else
		{
			quantityOfTeachers = allQuantity;
			quantityOfCandidates = candidatesQuantity;
			quantityOfDoctors = doctorsQuantity;
			return (false);
		}
	}
   

	//Get methods
	public String getFacultyName()
	{
		String outputString = String.copyValueOf(facultyName.toCharArray());
		return (outputString);
	}

	public int getQuantityOfStudents()
	{
		return quantityOfStudents;
	}

	public int getQuantityOfBachelors()
	{
		return quantityOfBachelors;
	}

	public int getQuantityOfMasters()
	{
		return quantityOfMasters;
	}

	public int getQuantityOfTeachers()
	{
		return quantityOfTeachers;
	}

	public int getQuantityOfCandidates()
	{
		return quantityOfCandidates;
	}

	public int getQuantityOfDoctors()
	{
		return quantityOfDoctors;
	}

	public int getQuantityOfDisciplines()
	{
		return quantityOfDisciplines;
	}	

	//Processing methods
	public double getProcentOfMasters()
	{
		return (((double) quantityOfMasters) / ((double) quantityOfStudents) * 100);
	}

	public double getProcentOfDoctors()
	{
		return (((double) quantityOfDoctors) / ((double) quantityOfTeachers) * 100);
	}

	public double getStudToTeachRatio()
	{
		return ((double) quantityOfStudents) / ((double) quantityOfTeachers);
	}

   public boolean Init(String bufFacultyName, int studentsQuantity, int bachelorsQuantity, int mastersQuantity, int teachersQuantity, int candidatesQuantity, int doctorsQuanity, int discpilinesQuantity)
   {
		Faculty check = new Faculty();
	
		if (check.setFacultyName(bufFacultyName) || check.setQuantityOfStudents(studentsQuantity) ||
			check.setQuantityOfBachelors(bachelorsQuantity) || check.setQuantityOfMasters(mastersQuantity) ||
			check.setQuantityOfTeachers(teachersQuantity) || check.setQuantityOfCandidates(candidatesQuantity) ||
			check.setQuantityOfDoctors(doctorsQuanity) || check.setQuantityOfDisciplines(discpilinesQuantity))
			return (true);
		else
		{
			this.setFacultyName(bufFacultyName);
			this.setQuantityOfStudents(studentsQuantity);
			this.setQuantityOfBachelors(bachelorsQuantity);
			this.setQuantityOfMasters(mastersQuantity);
			this.setQuantityOfTeachers(teachersQuantity);
			this.setQuantityOfCandidates(candidatesQuantity);
			this.setQuantityOfDoctors(doctorsQuanity);
			this.setQuantityOfDisciplines(discpilinesQuantity);
			return (false);
		}
   }

   public boolean read()
   {
		Faculty check = new Faculty();

		System.out.printf("Enter faculty name:\n");
		Scanner scanner = new Scanner(System.in);
		if (!scanner.hasNextLine())
			return (true);
		else
		{
			if (check.setFacultyName(scanner.nextLine()))
				return (true);
			else 
			{
				System.out.printf("Enter quantity of students:\n");
				if (!scanner.hasNextInt())
					return (true);
				else
				{
					if (check.setQuantityOfStudents(scanner.nextInt()))
						return (true);
					else
					{
						System.out.printf("Enter quantity of bachelors:\n");
						if (!scanner.hasNextInt())
							return (true);
						else
						{
							if (check.setQuantityOfBachelors(scanner.nextInt()))
								return (true);
							else
							{
								System.out.printf("Enter quantity of masters:\n");
								if (!scanner.hasNextInt())
									return (true);
								else
								{
									if (check.setQuantityOfMasters(scanner.nextInt()))
										return (true);
									else
									{
										System.out.printf("Enter quantity of teachers:\n");
										if (!scanner.hasNextInt())
											return (true);
										else
										{
											if (check.setQuantityOfTeachers(scanner.nextInt()))
												return (true);
											else
											{
												System.out.printf("Enter quantity of candidates:\n");
												if (!scanner.hasNextInt())
													return (true);
												else
												{
													if (check.setQuantityOfCandidates(scanner.nextInt()))
														return (true);
													else
													{
														System.out.printf("Enter quantity of doctors:\n");
														if (!scanner.hasNextInt())
															return (true);
														else
														{
															if (check.setQuantityOfDoctors(scanner.nextInt()))
																return (true);
															else
															{
																System.out.printf("Enter quantity of disciplines:\n");
																if (!scanner.hasNextInt())
																	return (true);
																else
																{
																	if (check.setQuantityOfDisciplines(scanner.nextInt()))
																		return (true);
																	else
																	{
																		setFacultyName(check.getFacultyName());
																		setQuantityOfStudents(check.getQuantityOfStudents());
																		setQuantityOfBachelors(check.getQuantityOfBachelors());
																		setQuantityOfMasters(check.getQuantityOfMasters());
																		setQuantityOfTeachers(check.getQuantityOfTeachers());
																		setQuantityOfCandidates(check.getQuantityOfTeachers());
																		setQuantityOfDoctors(check.getQuantityOfDoctors());
																		setQuantityOfDisciplines(check.getQuantityOfDisciplines());
																		return (false);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

   public void display()
   {
	System.out.printf("faculty name: %s\n", facultyName);
	System.out.printf("quantity of students: %d\n", quantityOfStudents);
	System.out.printf("quantity of bachelors: %d\n", quantityOfBachelors);
	System.out.printf("quantity of masters: %d\n\n", quantityOfMasters);

	System.out.printf("quantity of teachers: %d\n", quantityOfTeachers);
	System.out.printf("quantity of candidates: %d\n", quantityOfCandidates);
	System.out.printf("quantity of doctors: %d\n\n", quantityOfDoctors);

	System.out.printf("quantity of disciplines: %d\n", quantityOfDisciplines);
   }
}