#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm(copy),
	_target(copy._target)
{
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Exceptions
const char * ShrubberyCreationForm::UnplantableException::what() const throw()
{
	return "The shrubbery cannot be plantable";
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this != &assign)
	{
		_target = assign._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->eligible(executor);
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (ofs.fail())
	{
		throw UnplantableException();
	}
	ofs << "       _-_\n"
		<< "    /~~   ~~\\\n"
		<< " /~~         ~~\\\n"
		<< "{               }\n"
		<< " \\  _-     -_  /\n"
		<< "   ~  \\\\ //  ~\n"
		<< "_- -   | | _- _\n"
		<< "  _ -  | |   -_\n"
		<< "      // \\\\";
}
