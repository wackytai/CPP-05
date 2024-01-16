#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat &object );
		~Bureaucrat();
		Bureaucrat	&operator=( const Bureaucrat &object );
		Bureaucrat	operator++( void );
		Bureaucrat	operator--( void );
		void		setGrade( int i );
		std::string	getName ( void ) const;
		int			getGrade ( void ) const;
};

std::ostream 	&operator<< ( std::ostream &out, const Bureaucrat &object );

#endif