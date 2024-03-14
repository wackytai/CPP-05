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

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "Lowest grade already reached.";
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "Highest grade already reached.";
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &object )
{
	return (out << object.getName() << ", bureaucrat grade " << object.getGrade() << std::endl);
}
