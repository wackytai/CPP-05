#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( const std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &object );
		virtual	~PresidentialPardonForm();
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &object );
		int					action( void ) const;
};

#endif