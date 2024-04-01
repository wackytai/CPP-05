#include "../inc/Bureaucrat.hpp"

int	bureaucracy(std::string name, int grade)
{
	Bureaucrat brc(name, grade);

	std::cout << brc << std::endl;
	brc.incrementGrade();
	brc.incrementGrade();
	brc.incrementGrade();
	std::cout << brc << std::endl;
	brc.decrementGrade();
	brc.decrementGrade();
	brc.decrementGrade();
	brc.decrementGrade();
	std::cout << brc << std::endl;
	brc.setGrade(brc.getGrade() + 2);
	std::cout << brc << std::endl;
	brc.setGrade(brc.getGrade() - 40);
	std::cout << brc << std::endl;
	return 0;
}

int	test(std::string name, int grade)
{
	try
	{
		bureaucracy(name, grade);
	}
	catch ( Bureaucrat::GradeTooHighException &e )
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch ( Bureaucrat::GradeTooLowException &e )
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

int	main()
{
	test("Bureaucrat 01", 0);
	std::cout << std::endl;
	test("Bureaucrat 02", 151);
	std::cout << std::endl;
	test("Bureaucrat 03", 2);
	std::cout << std::endl;
	test("Bureaucrat 04", 150);
	std::cout << std::endl;
	test("Bureaucrat 05", 145);
	std::cout << std::endl;
	test("Bureaucrat 06", 3);
	std::cout << std::endl;
	test("Bureaucrat 07", 75);
	std::cout << std::endl;

	return 0;
}
