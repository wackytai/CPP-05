#ifndef	FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeS;
		const int			_gradeE;
	
	public:
		Form();
		Form( const std::string name, int grade );
		Form( const Form &object );
		~Form();
		Form		&operator=( const Form &object );
		std::string	getName( void ) const;
		bool		getStatus( void ) const;
		int			getSigningGrade( void ) const;
		int			getExecutionGrade( void ) const;
		void		setGrade( int i );
		void		setStatus( bool status );
		void		setSigningGrade( int grade );
		void		setExecutionGrade( int grade );
		bool		beSigned( const Bureaucrat &b );
};

std::ostream	operator<<( std::ostream &out, const Form &object );

#endif