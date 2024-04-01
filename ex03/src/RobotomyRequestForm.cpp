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
	*this = object;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &object )
{
	_target = object._target;
	setStatus(false);
	return *this;
}

int	RobotomyRequestForm::action( void ) const
{
	static int	i;

	std::cout << "* drilling noises *" << std::endl;
	if (i % 2 != 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " has failed to be robotomized." << std::endl;
	i++;
	return 1;
}
