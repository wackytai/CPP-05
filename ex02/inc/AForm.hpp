#ifndef	FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeS;
		const int			_gradeE;
		bool				_isSigned;
	
	public:
		AForm();
		AForm( const std::string name, int gradeS, int gradeE );
		AForm( const AForm &object );
		virtual 		~AForm();
		AForm			&operator=( const AForm &object );
		std::string		getName( void ) const;
		bool			getStatus( void ) const;
		int				getSigningGrade( void ) const;
		int				getExecutionGrade( void ) const;
		void			setStatus( bool status );
		void			beSigned( const Bureaucrat &b );
		virtual void	execute( Bureaucrat const &executor ) const = 0;
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
};

std::ostream	&operator<<( std::ostream &out, const AForm &object );

#endif