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

AForm * scformCreator(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm * rrformCreator(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm * ppformCreator(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target) const
{
	const size_t N_FORMS = 3;
	const std::string FORMS[N_FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
	AForm* (*FUNC_TABLE[N_FORMS])(std::string) = {
		scformCreator,
		rrformCreator,
		ppformCreator,
	};

	AForm * res = nullptr;
	for (size_t i = 0; i < N_FORMS; i++) {
		if (form == FORMS[i]) {
			res = FUNC_TABLE[i](target);
			std::cout << "Intern creates " << res->getName() << std::endl;
		}
	}
	if (res == nullptr)
		throw NoSuchFormException();
	return res;
}

const char * Intern::NoSuchFormException::what() const throw()
{
	return "The name of a form is not correct";
}