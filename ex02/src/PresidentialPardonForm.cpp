#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardon::PresidentialPardon() :AForm( "PresidentialPardon", 25, 5 )
{
	_target = "default";
	setStatus( false );
}

PresidentialPardon::PresidentialPardon( const std::string target ) :AForm( "PresidentialPardon", 25, 5 )
{
	_target = "default";
	setStatus( false );
}

PresidentialPardon::PresidentialPardon( const PresidentialPardon &object ) :AForm( "PresidentialPardon", 25, 5 )
{
	_target = object._target;
	setStatus( false );
	*this = object;
}

PresidentialPardon::~PresidentialPardon() {}

PresidentialPardon&	PresidentialPardon::operator=( const PresidentialPardon &object )
{
	_target = object._target;
	setStatus( false );
}

void	PresidentialPardon::execute( Bureaucrat const &executor ) const
{
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
