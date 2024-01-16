#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
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
		Bureaucrat( const Bureaucrat& object );
		~Bureaucrat();
		Bureaucrat& operator=( const Bureaucrat& object )
		ostream& 	operator<<( ostream& out, const Bureaucrat& object );
		void		setGrade( int i );
		std::string	getName ( void ) const;
		int			getGrade ( void ) const;
};

#endif