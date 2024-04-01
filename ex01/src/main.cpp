#include "../inc/Bureaucrat.hpp"

int	bureau_life(std::string name, int grade, std::string name2, int grade2, int grade3)
{
	Bureaucrat	desk_jockey(name, grade);
	Form		paperwork(name2, grade2, grade3);

	std::cout << desk_jockey << std::endl;
	std::cout << paperwork << std::endl;
	paperwork.beSigned(desk_jockey);
	desk_jockey.incrementGrade();
	std::cout << desk_jockey << std::endl;
	paperwork.beSigned(desk_jockey);
	return (0);
}

int	error_testing(std::string name, int grade, std::string name2, int grade2, int grade3)
{
	try
	{
		bureau_life(name, grade, name2, grade2, grade3);
	}
	catch(Form::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Form::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Form::FormSignedException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}

int	main(void)
{
	error_testing("Bureaucrat 01", 74, "form1", 0, 75);
	std::cout << std::endl;
	error_testing("Bureaucrat 02", 74, "form1", 151, 75);
	std::cout << std::endl;
	error_testing("Bureaucrat 03", 0, "form1", 75, 1);
	std::cout << std::endl;
	error_testing("Bureaucrat 04", 151, "form1", 0, 150);
	std::cout << std::endl;
	error_testing("Bureaucrat 05", 74, "form1", 75, 75);
	std::cout << std::endl;
	error_testing("Bureaucrat 06", 75, "form1", 75, 75);
	std::cout << std::endl;
	error_testing("Bureaucrat 07", 75, "form1", 74, 75);
	return (0);
}