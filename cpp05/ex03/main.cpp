#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern	someRandomIntern;
    AForm*	rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	try
	{
		rrf = someRandomIntern.makeForm("wrong form", "hep");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}