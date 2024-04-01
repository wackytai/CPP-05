#include "../inc/AForm.hpp"

AForm::AForm() : _name("form"), _gradeS(150), _gradeE(150), _isSigned(false) {}

AForm::AForm( const std::string name, int gradeS, int gradeE ) : _name( name ), _gradeS( gradeS ), _gradeE( gradeE ), _isSigned( false )
{
	if (_gradeS < 1 || _gradeE < 1)
		throw GradeTooHighException();
	if (_gradeS > 150 || _gradeE > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm &object ) : _name(object.getName()), _gradeS(object.getSigningGrade()), _gradeE(object.getExecutionGrade()) {}

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

void	AForm::beSigned( Bureaucrat &b )
{
	if (getStatus())
		throw FormSignedException();
	else if (b.getGrade() <= _gradeS)
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

void	AForm::execute( Bureaucrat const &executor ) const
{
	if (!getStatus())
		throw GradeTooLowException();
	else if (executor.getGrade() > getExecutionGrade())
		throw FormNotExecutedException();
	executor.executeForm(*this);
}

std::ostream	&operator<<( std::ostream &out, const AForm &object )
{
	return (out << object.getName() << ":\n" << " - signing grade: " << object.getSigningGrade() << "\n - execution grade: " << object.getExecutionGrade() << std::endl);
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too low";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too high";
}

const char	*AForm::FormSignedException::what() const throw()
{
	return "Form: Form is already signed";
}

const char	*AForm::FormNotExecutedException::what() const throw()
{
	return "Form: Form was not executed";
}
