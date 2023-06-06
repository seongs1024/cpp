#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include "Char.hpp"
#include "Double.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Nan.hpp"
#include "NegativeInf.hpp"
#include "PositiveInf.hpp"

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

AType * ScalarConverter::detectType(std::string &lit)
{
	if (lit.length() == 0)
		throw AType::ImpossibleConversionException();
	if (lit.length() == 1 && printable(lit[0]) && !in_digit(lit[0]))
		return new Char(lit);
	if (lit == "-inf" || lit == "-inff")
		return new NegativeInf();
	if (lit == "+inf" || lit == "inf" || lit == "+inff" || lit == "inff")
		return new PositiveInf();
	if (lit == "nan" || lit == "nanf")
		return new Nan();

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
			throw AType::ImpossibleConversionException();
	}

	if (last_f)
		return new Float(lit);
	else if (dot)
		return new Double(lit);
	// else if (!dot && last_f)
	// 	return Unknown;
	else
		return new Int(lit);
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
	AType * type = NULL;

	try
	{
		type = detectType(lit);
	}
	catch(const AType::ImpossibleConversionException& e)
	{
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: impossible\n"
			<< "double: impossible" << std::endl;
		return ;
	}
	if (type)
	{
		try
		{
			char c = static_cast<char>(*type);
			std::cout << "char: " << c << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "char: " << e.what() << std::endl;
		}
		try
		{
			int i = static_cast<int>(*type);
			std::cout << "int: " << i << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "int: " << e.what() << std::endl;
		}
		try
		{
			float f = static_cast<float>(*type);
			std::cout << "float: " << std::showpoint << f << "f" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "float: " << e.what() << std::endl;
		}
		try
		{
			double d = static_cast<double>(*type);
			std::cout << "double: " << std::showpoint << d << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "double: " << e.what() << std::endl;
		}
		delete type;
	}
}
