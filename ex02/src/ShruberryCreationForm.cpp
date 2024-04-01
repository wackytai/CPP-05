#include "../inc/ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm() : AForm("ShruberryCreationForm", 145, 137)
{

}

ShruberryCreationForm::ShruberryCreationForm( const std::string target ) : AForm("ShruberryCreationForm", 145, 137), _target(target)
{

}

ShruberryCreationForm::ShruberryCreationForm( const ShruberryCreationForm &object ) : AForm("ShruberryCreationForm", 145, 137)
{
	setStatus(false);
}

ShruberryCreationForm::~ShruberryCreationForm() {}

ShruberryCreationForm&	ShruberryCreationForm::operator=( const ShruberryCreationForm &object )
{
	_target = object._target;
	setStatus(object.getStatus());
	return *this;
}

void	ShruberryCreationForm::execute( Bureaucrat const &executor ) const
{
	std::ofstream outfile;
	std::string filename = _target + "_shrubbery";
	outfile.open(filename);
	outfile	<< "	   *    *  ()   *   *\n"
	<< "*        * /\\         *\n"
	<< "      *   /i\\\\    *  *\n"
	<< "    *     o/\\\\  *      *\n"
	<< " *       ///\\i\\    *\n"
	<< "     *   /*/o\\\\  *    *\n"
	<< "   *    /i//\\*\\      *\n"
	<< "        /o/*\\\\i\\   *\n"
	<< "  *    //i//o\\\\\\\\     *\n"
	<< "    * /*////\\\\\\\\i\\*\n"
	<< " *    //o//i\\\\*\\\\\\   *\n"
	<< "   * /i///*/\\\\\\\\\\o\\   *\n"
	<< "  *    *   ||     * " << std::endl;
	outfile.close();
}
