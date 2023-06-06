#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include "AType.hpp"

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

	private:
		ScalarConverter();

		static AType * detectType(std::string &lit);
};

#endif