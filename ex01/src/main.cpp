#include "../inc/Bureaucrat.hpp"

int	bureaucracy(std::string name, int grade)
{
	Bureaucrat brc(name, grade);

	std::cout << brc << std::endl;
	brc.upgrade();
	brc.upgrade();
	brc.upgrade();
	std::cout << brc << std::endl;
	brc.downgrade();
	brc.downgrade();
	brc.downgrade();
	brc.downgrade();
	std::cout << brc << std::endl;
	brc.setGrade(brc.getGrade() + 5);
	std::cout << brc << std::endl;
	brc.setGrade(brc.getGrade() - 10);
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
		std::cerr << e.what << std::endl;
		return 1;
	}
	catch ( Bureaucrat::GradeTooLowException &e )
	{
		std::cerr << e.what << std::endl;
		return 1;
	}
	return 0;
}

int	main()
{
	test("Form stacker", 0);
	test("Form stacker", 151);
	test("Form stacker", 2);
	test("Form stacker", 150);
	test("Form stacker", 145);
	test("Form stacker", 3);
	test("Form stacker", 75);

	return 0;
}
