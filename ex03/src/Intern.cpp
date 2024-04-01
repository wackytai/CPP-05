#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern &object )
{
	(void)object;
}

Intern::~Intern() {}

Intern& Intern::operator=( const Intern &object )
{
	(void)object;
}

AForm*	Intern::makeForm( const std::string formName, const std::string target )
{
	AForm	*form;

	std::string	formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*(Intern::*ptr[3])(std::string target) = {&Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			return (form = (this->*ptr[i])(target));
		}
	}
	throw InvalidFormNameException();
	return 0;
}

AForm*	Intern::makePresidentialPardonForm( const std::string target )
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeRobotomyRequestForm( const std::string target )
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makeShrubberyCreationForm( const std::string target )
{
	return new ShrubberyCreationForm(target);
}

const char* Intern::InvalidFormNameException::what() const throw()
{
	return "Invalid form name";
}
