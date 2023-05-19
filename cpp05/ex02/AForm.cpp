#include "AForm.hpp"

// Constructors
AForm::AForm(const AForm &copy):
	_name(copy.getName()),
	_singed(copy.getSinged()),
	_signed_grade(copy.getSignedGrade()),
	_executed_grade(copy.getExecutedGrade())
{
}

AForm::AForm(const std::string name, const int signed_grade, const int executed_grade):
	_name(name),
	_signed_grade(signed_grade),
	_executed_grade(executed_grade)
{
	this->_singed = false;
	if (this->_name.empty())
		throw NameRequiredException();
	if (this->_signed_grade < 1 || this->_executed_grade > 150)
		throw GradeTooHighException();
	if (this->_signed_grade > 150 || this->_executed_grade > 150)
		throw GradeTooLowException();
}


// Destructor
AForm::~AForm()
{
}


// Operators
AForm & AForm::operator=(const AForm &assign)
{
	if (this != &assign) {
		_singed = assign.getSinged();
	}
	return *this;
}


// Getters / Setters
const std::string AForm::getName() const
{
	return _name;
}
bool AForm::getSinged() const
{
	return _singed;
}
int AForm::getSignedGrade() const
{
	return _signed_grade;
}
int AForm::getExecutedGrade() const
{
	return _executed_grade;
}

void AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->_signed_grade)
		throw GradeTooLowException();
	this->_singed = true;
}

bool AForm::eligible(Bureaucrat const &executor) const
{
	if (this->getSinged() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecutedGrade())
		throw GradeTooLowException();
    return true;
}

// Exceptions
const char * AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too hight";
}
const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
const char * AForm::NameRequiredException::what() const throw()
{
	return "Name is empty";
}
const char * AForm::NotSignedException::what() const throw()
{
	return "The form is not signed";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object)
{
	stream << "" << object.getName() << ", form\n - Grade required to sign: " 
		<< object.getSignedGrade()
		<< "\n - Grade required to execute: " << object.getExecutedGrade() 
		<< "\n - Signed: ";
	if (object.getSinged())
		stream << "true" << std::endl;
	else
		stream << "false" << std::endl;
	return stream;
}
