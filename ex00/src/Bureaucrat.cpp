#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name( "bureaucrat" ), _grade( 1 )
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name( name ), _grade( grade )
{
	std::cout << "Bureaucrat Custom Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& object ) : _name( object.getName() ), _grade( object.getGrade() )
{
	*this = object;
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& object )
{
	(void) object;
	return *this;
}

ostream& operator<<( ostream& out, const Bureaucrat& object )
{
	out << getName() << ", bureaucrat grade " << getGrade() << std::endl;
	return out;
}

void		Bureaucrat::setGrade( int i )
{
	_grade = i;
}

std::string	Bureaucrat::getName ( void ) const
{
	return _name;
}

int			Bureaucrat::getGrade ( void ) const
{
	return _grade;
}
