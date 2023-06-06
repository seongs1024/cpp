#include "Float.hpp"
#include <sstream>
#include <limits>

// Constructors
Float::Float(std::string &lit)
{
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail())
		throw ImpossibleConversionException();
}

Float::Float(const Float &copy): AType()
{
	*this = copy;
}

// Destructor
Float::~Float()
{
}


// Operators
Float & Float::operator=(const Float &assign)
{
	if (this != &assign)
		_value = assign._value;
	return *this;
}

Float::operator char() const
{
	char c;

	if(_value > std::numeric_limits<char>::max() ||
		_value < std::numeric_limits<char>::min())
		throw ImpossibleConversionException();
	c = static_cast<char>(_value);
	if (AType::printable(c) == false)
		throw NonDisplayableException();
	return c;
}

Float::operator int() const
{
	if(_value > std::numeric_limits<int>::max() ||
		_value < std::numeric_limits<int>::min())
		throw ImpossibleConversionException();
	return static_cast<int>(_value);
}

Float::operator float() const
{
	return _value;
}

Float::operator double() const
{
	return static_cast<double>(_value);
}
