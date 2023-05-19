#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat a("BurA", 3);
	ShrubberyCreationForm scf("home");
	RobotomyRequestForm rrf("robomy");
	PresidentialPardonForm ppf("zb");

	try
	{
		a.signForm(scf);
		a.executeForm(scf);

		a.signForm(rrf);
		a.executeForm(rrf);

		a.signForm(ppf);
		a.executeForm(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}