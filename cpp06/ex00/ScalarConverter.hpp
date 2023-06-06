#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

enum Type
{
	Char,
	Int,
	Float,
	Double,
};

class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter(const ScalarConverter &copy);
		
		// Destructor
		~ScalarConverter();
		
		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);
		
		static void convert(std::string lit);

		class ImpossibleConversionException : public std::exception {
			virtual const char* what() const throw();
		};
		class PositiveInfException : public std::exception {
			virtual const char* what() const throw();
		};
		class NegativeInfException : public std::exception {
			virtual const char* what() const throw();
		};
		class NanException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		ScalarConverter();

		static Type detectType(std::string &lit);
		// static std::ostringstream toChar(std::string &)
};

#endif