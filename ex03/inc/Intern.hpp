#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern( const Intern &object );
		~Intern();
		Intern& operator=( const Intern &object );
		AForm*	makeForm( const std::string formName, const std::string target );
		AForm*	makePresidentialPardonForm( const std::string target );
		AForm*	makeRobotomyRequestForm( const std::string target );
		AForm*	makeShrubberyCreationForm( const std::string target );
		class InvalidFormNameException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif