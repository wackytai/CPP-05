#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :AForm( "PresidentialPardonForm", 25, 5 )
{
	_target = "default";
	setStatus( false );
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) :AForm( "PresidentialPardonForm", 25, 5 )
{
	_target = target;
	setStatus( false );
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &object ) :AForm( "PresidentialPardonForm", 25, 5 )
{
	*this = object;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm &object )
{
	_target = object._target;
	setStatus( false );
	return *this;
}

int	PresidentialPardonForm::action( void ) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return 1;
}
