#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


// Constructors
Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}


// Destructor
Intern::~Intern()
{
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

AForm * scformConstructor(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm * rrformConstructor(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm * ppformConstructor(std::string target) {
	return new PresidentialPardonForm(target);
}

typedef AForm * (*AFormConstructor)(std::string);

AForm *Intern::makeForm(std::string form, std::string target) const
{
	const size_t N_FORMS = 3;
	const std::string FORMS[N_FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
	AFormConstructor FUNC_TABLE[N_FORMS] = {
		scformConstructor,
		rrformConstructor,
		ppformConstructor,
	};

	AForm * res = NULL;
	for (size_t i = 0; i < N_FORMS; i++) {
		if (form == FORMS[i]) {
			res = FUNC_TABLE[i](target);
			std::cout << "Intern creates " << res->getName() << std::endl;
		}
	}
	if (res == NULL)
		throw NoSuchFormException();
	return res;
}

const char * Intern::NoSuchFormException::what() const throw()
{
	return "The name of a form is not correct";
}