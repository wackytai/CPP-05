#ifndef	FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeS;
		const int			_gradeE;
		bool				_isSigned;
	
	public:
		Form();
		Form( const std::string name, int gradeS, int gradeE );
		Form( const Form &object );
		~Form();
		Form		&operator=( const Form &object );
		std::string	getName( void ) const;
		bool		getStatus( void ) const;
		int			getSigningGrade( void ) const;
		int			getExecutionGrade( void ) const;
		void		setStatus( bool status );
		void		beSigned( Bureaucrat &b );
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class FormSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<( std::ostream &out, const Form &object );

#endif