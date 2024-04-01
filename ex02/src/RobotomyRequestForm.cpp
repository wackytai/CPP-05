#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default";
	setStatus(false);
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
	setStatus(false);
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &object ) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = object._target;
	setStatus(false);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &object )
{
	if (_target != object._target)
		_target = object._target;
	setStatus(object.getStatus());
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	static int	i;

	if (executor.getGrade() > getExecutionGrade())
	{
		std::cout << getName() << " execution failed: ";
		throw AForm::GradeTooLowException();
	}
	std::cout << "* drilling noises *" << std::endl;
	if (i % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " has failed to be robotomized." << std::endl;
}
