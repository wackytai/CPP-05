#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &object );
		virtual 		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &object );
		void	execute( Bureaucrat const &executor ) const;
};

#endif