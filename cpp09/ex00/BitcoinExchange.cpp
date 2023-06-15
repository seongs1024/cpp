#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

// Constructors
BitcoinExchange::BitcoinExchange(const char * price_db_path)
{
	std::ifstream price_db(price_db_path);
	if (!price_db.is_open())
		throw FileOpenException();
	prices = serialize(price_db, "date,exchange_rate", ",");
}


// Destructor
BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::Prices BitcoinExchange::serialize(
	std::istream & ifs,
	const std::string & header_fmt,
	const std::string & delim_fmt)
{
	Prices prices;
	std::string line;
	
	header(ifs, header_fmt);
	while (std::getline(ifs, line))
	{
		std::stringstream ss(line);

		Date date;
		double price;

		ss >> date;
		delim(ss, delim_fmt);
		ss >> price;
		if (ss.fail())
			throw BadDbException();
		if (price < 0)
			throw BadDbException();

		prices.insert(std::pair<Date, double>(date, price));
	}
	if (prices.size() == 0)
		throw EmptyFileException();
	
    return prices;
}

void BitcoinExchange::factored_price(
	std::istream & ifs,
	const std::string & header_fmt,
	const std::string & delim_fmt)
{
	std::string line;
	
	header(ifs, header_fmt);
	while (std::getline(ifs, line))
	{
		try
		{
			std::stringstream ss(line);

			Date date;
			double price;

			ss >> date;
			delim(ss, delim_fmt);
			ss >> price;
			if (ss.fail())
				throw BadInputException();
			if (price < 0)
				throw NotPositiveNumberException();
			if (price > 1000)
				throw TooLargeNumberException();

			for (Prices::const_iterator it = prices.begin(); it != prices.end(); ++it)
			{
				Prices::const_iterator next = it;
				std::advance(next, 1);
				if (it->first == date || next == prices.end())
				{
					// std::cout << "LB: " << (it->first).year << '-' << (it->first).month << '-' << (it->first).day << ": ";
					std::cout << date.year << '-' << date.month << '-' << date.day << " => "
						<< price << " = " << price * (it->second) << std::endl;
					break ;
				}
				else if (date < it->first)
				{
					it--;
					// std::cout << "LB: " << (it->first).year << '-' << (it->first).month << '-' << (it->first).day << ": ";
					std::cout << date.year << '-' << date.month << '-' << date.day << " => "
						<< price << " = " << price * (it->second) << std::endl;
					break ;
				}
			}
		}
		catch(const BadInputException & e)
		{
			std::cerr << "Error: " << e.what() << line << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::header(std::istream &ifs, std::string fmt)
{
	std::string line;
	std::getline(ifs, line);
	if (line != fmt)
		throw BadHeaderException();
}

void BitcoinExchange::delim(std::istream &is, std::string fmt)
{
	for(std::string::const_iterator it = fmt.begin(); it != fmt.end(); ++it)
	{
		if (is.get() != *it)
			throw BadInputException();
	}
}

// Exceptions
const char * BitcoinExchange::NotPositiveNumberException::what() const throw()
{
	return "not a positive number.";
}
const char * BitcoinExchange::FileOpenException::what() const throw()
{
	return "could not open file.";
}
const char *BitcoinExchange::BadHeaderException::what() const throw()
{
    return "there's problem in the header.";
}
const char * BitcoinExchange::BadInputException::what() const throw()
{
	return "bad input => ";
}
const char * BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "too large a number.";
}
const char *BitcoinExchange::EmptyFileException::what() const throw()
{
    return "empty file.";
}
const char *BitcoinExchange::BadDbException::what() const throw()
{
    return "bad db";
}

std::istream &operator>>(std::istream &ss, Date &date)
{
	ss >> date.year;
	if (date.year < 1970 || date.year > 2038 || ss.get() != '-') {
		ss.setstate(std::ios_base::failbit);
		return ss;
	}
	ss >> date.month;
	if (date.month < 1 || date.month > 12 || ss.get() != '-') {
		ss.setstate(std::ios_base::failbit);
		return ss;
	}
	ss >> date.day;
	if (((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) && (date.day < 1 || date.day > 31)) ||
		((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && (date.day < 1 || date.day > 30)) ||
		((date.month == 2) && (((date.year % 4 == 0) && (date.year % 100 != 0 || date.year % 400 == 0)) && (date.day < 1 || date.day > 29))) ||
		((date.month == 2) && (!((date.year % 4 == 0) && (date.year % 100 != 0 || date.year % 400 == 0)) && (date.day < 1 || date.day > 28)))) {
		ss.setstate(std::ios_base::failbit);
		return ss;
	}
	return ss;
}

bool Date::operator<(const Date &rhs) const
{
	if (year < rhs.year)
		return year < rhs.year;
	if (month < rhs.month)
		return month < rhs.month;
	return day < rhs.day;
}

bool Date::operator==(const Date &rhs) const
{
	if (year != rhs.year)
		return false;
	if (month != rhs.month)
		return false;
	return day == rhs.day;
}
