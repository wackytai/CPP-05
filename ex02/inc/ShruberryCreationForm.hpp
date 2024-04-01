#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class ShruberryCreationForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		ShruberryCreationForm();
		ShruberryCreationForm( const std::string target );
		ShruberryCreationForm( const ShruberryCreationForm &object );
		virtual 				~ShruberryCreationForm();
		ShruberryCreationForm	&operator=( const ShruberryCreationForm &object );
		void					execute( Bureaucrat const &executor ) const;
};

#endif