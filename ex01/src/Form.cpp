#include "../inc/Form.hpp"

Form::Form()
{

}

Form::Form( const std::string name, int grade ) : _name( name ), 
{

}

Form::Form( const Form &object ) : _name(object.getName())
{
	*this = object;
}

Form::~Form() {}

Form		&Form::operator=( const Form &object )
{
	setGrade(object.getGrade());
	setStatus(object.getStatus());
	setSigningGrade(object.getSigningGrade());
	setExecutionGrade(object.getExecutionGrade());
	return *this ;
}

std::string	Form::getName( void ) const
{
	return _name ;
}

bool		Form::getStatus( void ) const
{
	return _isSigned ;
}

int			Form::getSigningGrade( void ) const
{
	return _gradeS ;
}

int			Form::getExecutionGrade( void ) const
{
	return _gradeE ;
}

void		Form::setGrade( int i )
{

}

void		Form::setStatus( bool status )
{

}

void		Form::setSigningGrade( int grade )
{

}

void		Form::setExecutionGrade( int grade )
{

}

bool		Form::beSigned( const Bureaucrat &b )
{

}

std::ostream	operator<<( std::ostream &out, const Form &object )
{
	return (out << object.getName() << ", signing grade " << object.getSigningGrade() << ", execution grade " << std::endl);
}
