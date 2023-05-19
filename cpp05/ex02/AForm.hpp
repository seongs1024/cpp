#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm(const std::string name, const int signed_grade, const int executed_grade);
		AForm(const AForm &copy);
		
		// Destructor
		~AForm();
		
		// Operators
		AForm & operator=(const AForm &assign);
		
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
		class NotSignedException : public std::exception {
			virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat & bur);
		
		virtual void execute(Bureaucrat const & executor) const = 0;

	protected:
		bool eligible(Bureaucrat const & executor) const;

	private:
		AForm();
		const std::string _name;
		bool _singed;
		const int _signed_grade;
		const int _executed_grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object);

#endif