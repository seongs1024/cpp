#ifndef ATYPE_HPP
# define ATYPE_HPP

# include <string>

class AType
{
	public:
		// Constructors
		AType();
		AType(const AType &copy);
		
		// Destructor
		virtual ~AType();
		
		// Operators
		AType & operator=(const AType &assign);
		
		// Exceptions
		class ImpossibleConversionException : public std::exception {
			virtual const char* what() const throw();
		};
		class NonDisplayableException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const = 0;
        virtual operator int() const = 0;
        virtual operator float() const = 0;
        virtual operator double() const = 0;

		static bool printable(char c);
		static bool in_digit(char c);

};

#endif