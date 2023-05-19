#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <iostream>

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm(copy),
	_target(copy._target)
{
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	if (this != &assign)
	{
		_target = assign._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->eligible(executor);
	std::cout << "Bzzzzzz... ";
	if (this->successful())
		std::cout << this->_target << " succeeded to be robotomized!" << std::endl;
	else
		std::cout << this->_target << " failed to be robotomized!" << std::endl;
}

bool RobotomyRequestForm::successful() const
{
	std::time_t result = std::time(0);
    return result % 2;
}
