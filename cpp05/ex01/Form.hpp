#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form(const std::string name, const int signed_grade, const int executed_grade);
		Form(const Form &copy);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Getters / Setters
		const std::string getName() const;
		bool getSinged() const;
		int getSignedGrade() const;
		int getExecutedGrade() const;
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		class NameRequiredException : public std::exception {
			virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat & bur);
		
	private:
		const std::string _name;
		bool _singed;
		const int _signed_grade;
		const int _executed_grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object);

#endif