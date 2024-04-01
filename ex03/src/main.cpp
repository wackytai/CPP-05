#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int	company_life(std::string name, int grade, std::string form, std::string target, AForm **new_form)
{
	Bureaucrat	desk_jockey(name, grade);
	Intern		fng;

	*new_form = fng.makeForm(form, target);
	(*new_form)->beSigned(desk_jockey);
	(*new_form)->execute(desk_jockey);
	return (0);
}

int	error_testing(std::string name, int grade, std::string form, std::string target)
{
	AForm		*new_form = NULL;
	try
	{
		company_life(name, grade, form, target, &new_form);
	}
	catch(Intern::InvalidFormNameException &error)
	{
		std::cerr << error.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Exception caught" << std::endl;
	}
	if (new_form != NULL)
		delete new_form;
	return (0);
}

int	main(void)
{
	error_testing("Bureaucrat 01", 74, "random", "the moon");
	std::cout << std::endl;
	error_testing("Bureaucrat 02", 10, "shrubbery creation", "parking lot");
	std::cout << std::endl;
	error_testing("Bureaucrat 03", 1, "ROBOTOMY REQUEST", "fng");
	std::cout << std::endl;
	error_testing("Bureaucrat 04", 1, "PrEsIdEnTiAl PaRdOn", "CEO");
	std::cout << std::endl;
	error_testing("Bureaucrat 05", 1, "robotomy creation", "everyone");
	std::cout << std::endl;
	return (0);
}