#include "../inc/Form.hpp"

Form::Form() : _name("form"), _gradeS(150), _gradeE(150), _isSigned(false) {}

Form::Form( const std::string name, int gradeS, int gradeE ) : _name( name ), _gradeS( gradeS ), _gradeE( gradeE ), _isSigned( false )
{
	if (_gradeS < 1 || _gradeE < 1)
		throw GradeTooHighException();
	else if (_gradeS > 150 || _gradeE > 150)
		throw GradeTooLowException();
}

Form::Form( const Form &object ) : _name(object.getName()), _gradeS(object.getSigningGrade()), _gradeE(object.getExecutionGrade()) {}

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

void	Form::beSigned( Bureaucrat &b )
{
	if (b.getGrade() <= _gradeS)
	{
		setStatus(true);
		b.signForm(getName(), 0);
	}
	else
	{
		b.signForm(getName(), 1);
		throw Form::GradeTooLowException();
	}
}

std::ostream	&operator<<( std::ostream &out, const Form &object )
{
	return (out << object.getName() << ":\n" << " - signing grade: " << object.getSigningGrade() << "\n - execution grade: " << object.getExecutionGrade() << std::endl);
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too low";
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too high";
}
