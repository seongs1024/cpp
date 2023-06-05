#include "Bureaucrat.hpp"

int main() {
	try
	{
		Bureaucrat a("A", 150);
		Form form("contract", 150, 150);
		a.signForm(form);
		std::cout << form;

		Bureaucrat b("B", 150);
		Form form2("higher contract", 149, 150);
		b.signForm(form2);
		std::cout << form2;

		a.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}