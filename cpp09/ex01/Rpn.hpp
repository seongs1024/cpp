#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class Rpn
{
	public:
		Rpn(std::string expr);
		
		// Destructor
		~Rpn();

		// Exceptions
		class WrongToken : public std::exception {
			virtual const char* what() const throw();
		};
		class DividedZero : public std::exception {
			virtual const char* what() const throw();
		};

		double calc();
		
	private:
		Rpn();
		Rpn(const Rpn &copy);
		Rpn & operator=(const Rpn &assign);

		std::stack<double> stack;
};

#endif