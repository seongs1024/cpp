#include "Form.hpp"

// Constructors
Form::Form(const Form &copy):
	_name(copy.getName()),
	_singed(copy.getSinged()),
	_signed_grade(copy.getSignedGrade()),
	_executed_grade(copy.getExecutedGrade())
{
}

Form::Form(const std::string name, const int signed_grade, const int executed_grade):
	_name(name),
	_signed_grade(signed_grade),
	_executed_grade(executed_grade)
{
	this->_singed = false;
	if (this->_name.empty())
		throw NameRequiredException();
	if (this->_signed_grade < 1 || this->_executed_grade < 1)
		throw GradeTooHighException();
	if (this->_signed_grade > 150 || this->_executed_grade > 150)
		throw GradeTooLowException();
}


// Destructor
Form::~Form()
{
}


// Operators
Form & Form::operator=(const Form &assign)
{
	if (this != &assign) {
		_singed = assign.getSinged();
	}
	return *this;
}


// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}
bool Form::getSinged() const
{
	return _singed;
}
int Form::getSignedGrade() const
{
	return _signed_grade;
}
int Form::getExecutedGrade() const
{
	return _executed_grade;
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->_signed_grade)
		throw GradeTooLowException();
	this->_singed = true;
}

// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade is too hight";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
const char * Form::NameRequiredException::what() const throw()
{
	return "Name is empty";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
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
