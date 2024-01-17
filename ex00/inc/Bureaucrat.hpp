#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

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
		void		setGrade( int amount );
		std::string	getName ( void ) const;
		int			getGrade ( void ) const;
		void		incrementGrade ( void );
		void		decrementGrade ( void );
		bool		checkGrade ( int grade );
		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what( void ) const throw();
		};
		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what( void ) const throw();
		};
};

std::ostream 	&operator<< ( std::ostream &out, const Bureaucrat &object );

#endif