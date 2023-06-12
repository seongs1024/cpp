#include "BitcoinExchange.hpp"
#include <fstream>

// Constructors
BitcoinExchange::BitcoinExchange(const char * price_db_path, const char * temp)
{
	prices = makePrices(price_db_path);

	std::ifstream stream(temp);
	if (!stream.is_open())
		throw FileOpenException();
}


// Destructor
BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::Prices BitcoinExchange::makePrices(const char *price_db_path)
{
	std::ifstream stream(price_db_path);
	if (!stream.is_open())
		throw PriceDbNotExistsException();

	std::string line;
	std::getline(stream, line);
	if (line != "date,exchange_rate")
		throw CorruptedFileException();
    return Prices();
}

// Getters / Setters


// Exceptions
const char * BitcoinExchange::NotPositiveNumberException::what() const throw()
{
	return "not a positive number.";
}
const char * BitcoinExchange::FileOpenException::what() const throw()
{
	return "could not open file.";
}
const char * BitcoinExchange::BadInputException::what() const throw()
{
	return "bad input";
}
const char * BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "too large a number.";
}
const char * BitcoinExchange::PriceDbNotExistsException::what() const throw()
{
	return "price database doesn't exist.";
}

const char *BitcoinExchange::CorruptedFileException::what() const throw()
{
    return "the file is corrupted.";
}
