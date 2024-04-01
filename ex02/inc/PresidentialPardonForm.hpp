#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP
# include "AForm.hpp"

class PresidentialPardon : public AForm
{
	private:
		std::string	_target;
	
	public:
		PresidentialPardon();
		PresidentialPardon( const std::string target );
		PresidentialPardon( const PresidentialPardon &object );
		virtual	~PresidentialPardon();
		PresidentialPardon	&operator=( const PresidentialPardon &object );
		void	execute( Bureaucrat const &executor ) const;
};

#endif