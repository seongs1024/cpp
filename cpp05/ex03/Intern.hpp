#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
		class NoSuchFormException : public std::exception {
			virtual const char* what() const throw();
		};

		AForm * makeForm(std::string form, std::string target) const;
	private:
		
};

#endif