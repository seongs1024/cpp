#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

// Constructors
ScalarConverter::ScalarConverter()
{
}

bool printable(char c)
{
	return c >= 0x20 && c < 0x7f;
}

bool in_digit(char c)
{
	return c >= '0' && c <= '9';
}

Type ScalarConverter::detectType(std::string &lit)
{
	if (lit.length() == 0)
		throw ImpossibleConversionException();
	if (lit.length() == 1 && printable(lit[0]))
		return Char;
	if (lit == "-inf" || lit == "-inff")
		throw NegativeInfException();
	if (lit == "+inf" || lit == "inf" || lit == "+inff" || lit == "inff")
		throw PositiveInfException();
	if (lit == "nan" || lit == "nanf")
		throw NanException();

	bool dot = false, last_f = false;
	for (size_t i = 0; i < lit.length(); i++)
	{
		if (in_digit(lit[i]))
			continue;
		else if (lit[i] == '.' && dot == false)
			dot = true;
		else if (lit[i] == 'f' && i == lit.length() - 1)
			last_f = true;
		else if ((lit[i] == '-' || lit[i] == '+') && i == 0)
			continue;
		else
			throw ImpossibleConversionException();
	}

	if (last_f)
		return Float;
	else if (dot)
		return Double;
	// else if (!dot && last_f)
	// 	return Unknown;
	else
		return Int;
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
	std::stringstream ss(lit);
	char c;
	double d;
	float f;
	int i;

	try
	{
		switch (detectType(lit))
		{
		case Char:
			ss >> c;
			if (ss.fail())
				throw ImpossibleConversionException();
			std::cout
				<< "char: " << c << "\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << std::showpoint << static_cast<float>(c) << "f\n"
				<< "double: " << std::showpoint << static_cast<double>(c) << std::endl;
			break;
		case Int:
			ss >> i;
			if (ss.fail())
				throw ImpossibleConversionException();
			std::cout
				<< "char: " << static_cast<char>(i) << "\n"
				<< "int: " << i << "\n"
				<< "float: " << std::showpoint << static_cast<float>(i) << "f\n"
				<< "double: " << std::showpoint << static_cast<double>(i) << std::endl;
			break;
		case Float:
			ss >> f;
			if (ss.fail())
				throw ImpossibleConversionException();
			std::cout
				<< "char: " << static_cast<char>(f) << "\n"
				<< "int: " << static_cast<int>(f) << "\n"
				<< "float: " << std::showpoint << f << "f\n"
				<< "double: " << std::showpoint << static_cast<double>(f) << std::endl;
			break;
		case Double:
			ss >> d;
			if (ss.fail())
				throw ImpossibleConversionException();
			std::cout
				<< "char: " << static_cast<char>(d) << "\n"
				<< "int: " << static_cast<int>(d) << "\n"
				<< "float: " << std::showpoint << static_cast<float>(d) << "f\n"
				<< "double: " << std::showpoint << d << std::endl;
			break;
		default:
			throw ImpossibleConversionException();
			break;
		}
	}
	catch(const ScalarConverter::ImpossibleConversionException& e)
	{
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: impossible\n"
			<< "double: impossible" << std::endl;
	}
	catch(const ScalarConverter::PositiveInfException& e)
	{
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: +inff\n"
			<< "double: +inf" << std::endl;
	}
	catch(const ScalarConverter::NegativeInfException& e)
	{
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: -inff\n"
			<< "double: -inf" << std::endl;
	}
	catch(const ScalarConverter::NanException& e)
	{
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: nanf\n"
			<< "double: nan" << std::endl;
	}

}

// Exceptions
const char * ScalarConverter::ImpossibleConversionException::what() const throw()
{
	return "impossible";
}
const char * ScalarConverter::PositiveInfException::what() const throw()
{
	return "+inf";
}
const char * ScalarConverter::NegativeInfException::what() const throw()
{
	return "-inf";
}
const char * ScalarConverter::NanException::what() const throw()
{
	return "nan";
}