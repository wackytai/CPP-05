#include "../inc/AForm.hpp"

AForm::AForm() : _name("form"), _gradeS(150), _gradeE(150), _isSigned(false) {}

AForm::AForm( const std::string name, int gradeS, int gradeE ) : _name( name ), _gradeS( gradeS ), _gradeE( gradeE ), _isSigned( false )
{
	if (_gradeS < 1 || _gradeE < 1)
		throw GradeTooHighException();
	else if (_gradeS > 150 || _gradeE > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm &object ) : _name(object.getName()), _gradeE(object.getExecutionGrade()), _gradeS(object.getSigningGrade()) {}

AForm::~AForm() {}

AForm		&AForm::operator=( const AForm &object )
{
	setStatus(object.getStatus());
	return *this ;
}

std::string	AForm::getName( void ) const
{
	return _name ;
}

bool		AForm::getStatus( void ) const
{
	return _isSigned ;
}

int			AForm::getSigningGrade( void ) const
{
	return _gradeS ;
}

int			AForm::getExecutionGrade( void ) const
{
	return _gradeE ;
}

void		AForm::setStatus( bool status )
{
	_isSigned = status;
}

void	AForm::beSigned( const Bureaucrat &b )
{
	if (b.getGrade() <= _gradeS)
	{
		setStatus(true);
		b.signForm(getName(), 0);
	}
	else
	{
		b.signForm(getName(), 1);
		throw GradeTooLowException();
	}
}

std::ostream	&operator<<( std::ostream &out, const AForm &object )
{
	return (out << object.getName() << ":\n" << " - signing grade: " << object.getSigningGrade() << "\n - execution grade: " << object.getExecutionGrade() << std::endl);
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}
