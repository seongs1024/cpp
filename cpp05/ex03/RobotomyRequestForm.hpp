#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm: public virtual AForm
{
	public:
		// Constructors
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		// Destructor
		virtual ~RobotomyRequestForm();
		
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
		void execute(Bureaucrat const & executor) const;

	private:
		RobotomyRequestForm();
		bool successful() const;

		std::string _target;
		
};

#endif