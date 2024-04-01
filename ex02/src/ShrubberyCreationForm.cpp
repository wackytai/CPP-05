#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default";
	setStatus(false);
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	setStatus( false );
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &object ) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = object;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm &object )
{
	_target = object._target;
	setStatus(false);
	return *this;
}

int	ShrubberyCreationForm::action( void ) const
{
	std::ofstream outfile;
	std::string filename = _target + "_shrubbery";
	outfile.open(filename.c_str());
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
	return 1;
}
