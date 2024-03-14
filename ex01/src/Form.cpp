#include "../inc/Form.hpp"

Form::Form()
{
	//initializer list of variables
}

Form::Form( const std::string name, int grade ) : _name( name ), 
{
	//finish initializer list
}

Form::Form( const Form &object ) : _name(object.getName()), _gradeE(object.getExecutionGrade()), _gradeS(object.getSigningGrade())
{
	*this = object;
}

Form::~Form() {}

Form		&Form::operator=( const Form &object )
{
	setStatus(object.getStatus());
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

void		Form::setStatus( bool status )
{
	_isSigned = status;
}

bool		Form::beSigned( const Bureaucrat &b )
{
	//check if bureaucrat has grade to sign
}

std::ostream	&operator<<( std::ostream &out, const Form &object )
{
	return (out << object.getName() << ", signing grade " << object.getSigningGrade() << ", execution grade " << std::endl);
}
