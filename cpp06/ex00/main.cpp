#include <iostream>
#include "ScalarConverter.hpp"

int main() {
	ScalarConverter::convert("42.5f");
	ScalarConverter::convert("2147483648.0");
	ScalarConverter::convert("42");
	ScalarConverter::convert("c");
	ScalarConverter::convert("f");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("inf");
}