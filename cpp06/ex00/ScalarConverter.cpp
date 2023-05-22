#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

// Constructors
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
}


// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

void ScalarConverter::convert(std::string lit)
{
	std::stringstream	ss_c(lit);
	std::stringstream	ss_i(lit);
	std::stringstream	ss_f(lit);
	std::stringstream	ss_d(lit);

	std::cout
		<< "char: " << static_cast<char>(ss_c) << "\n"
		<< "int: " << i << "\n"
		<< "float: " << f << "\n"
		<< "double: " << d << std::endl;
}
