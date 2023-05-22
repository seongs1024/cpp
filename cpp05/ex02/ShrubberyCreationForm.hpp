#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm: public virtual AForm
{
	public:
		// Constructors
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		
		// Destructor
		virtual ~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
		class UnplantableException : public std::exception {
			virtual const char* what() const throw();
		};

		void execute(Bureaucrat const & executor) const;

	private:
		ShrubberyCreationForm();
		std::string _target;
		
};

#endif