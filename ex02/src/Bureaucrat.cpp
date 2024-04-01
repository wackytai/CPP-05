#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name( "bureaucrat" ), _grade( 150 ) {}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name( name ), _grade( grade )
{
	checkGrade( grade );
}

Bureaucrat::Bureaucrat( const Bureaucrat &object ) : _name( object.getName() ), _grade( object.getGrade() ) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &object )
{
	_grade = object.getGrade();
	return *this;
}

void		Bureaucrat::setGrade( int amount )
{
	if (checkGrade(amount))
		_grade = amount;
}

std::string	Bureaucrat::getName ( void ) const
{
	return _name;
}

int			Bureaucrat::getGrade ( void ) const
{
	return _grade;
}

void		Bureaucrat::incrementGrade ( void )
{
	setGrade(getGrade() - 1);
}

void		Bureaucrat::decrementGrade ( void )
{
	setGrade(getGrade() + 1);
}

bool		Bureaucrat::checkGrade( int grade )
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return true ;
}

void		Bureaucrat::signForm( std::string name, int status ) const
{
	switch (status)
	{
		case 0:
			std::cout << getName() << " signed " << name << std::endl;
			break;
		default:
			std::cout << getName() << "couldn't sign " << name << " because bureaucrat's grade is too low." << std::endl;
			break;
	}
	return ;
}

void		Bureaucrat::executeForm( AForm const &form ) const
{
	if (form.getStatus() && getGrade() <= form.getExecutionGrade())
		std::cout << getName() << " executed " << form.getName() << std::endl;
	else
		if (form.getStatus())
			std::cout << getName() << "couldn't execute " << form.getName() << "because bureaucrat's grade is too low." << std::endl;
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "Lowest grade reached.";
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "Highest grade reached.";
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &object )
{
	return (out << object.getName() << ", bureaucrat grade " << object.getGrade() << std::endl);
}
