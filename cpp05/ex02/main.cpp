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
	Bureaucrat b("BurB", 65);

	try
	{
		a.signForm(scf);
		a.executeForm(scf);

		b.signForm(rrf);
		a.executeForm(rrf);

		a.signForm(ppf);
		a.executeForm(ppf);

		a.signForm(rrf);
		b.signForm(rrf);
		b.executeForm(rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}