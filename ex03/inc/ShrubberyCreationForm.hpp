#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &object );
		virtual 				~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &object );
		int						action( void ) const;
};

#endif