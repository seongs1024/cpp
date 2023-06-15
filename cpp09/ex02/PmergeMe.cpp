#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>

// Constructors
PmergeMe::PmergeMe(int size): _size(size)
{
	if (_size < 1)
		throw WrongToken();
	_con1.reserve(_size);
}

// Destructor
PmergeMe::~PmergeMe()
{
}

void PmergeMe::push(std::string lit)
{
	std::stringstream ss(lit);
	int num;

	ss >> num;
	if (ss.fail() || num < 0)
		throw WrongToken();
	if (_con1.size() >= _size || _con2.size() >= _size)
		throw WrongToken();
	_con1.push_back(num);
	_con2.push_back(num);
}

void PmergeMe::printCon1(void) const
{
	for (Container1::const_iterator it = _con1.begin(); it != _con1.end(); ++it)
	{
		std::cout << '\t' << *it;
	}
}

void PmergeMe::printCon2(void) const
{
	for (Container2::const_iterator it = _con2.begin(); it != _con2.end(); ++it)
	{
		std::cout << '\t' << *it;
	}
}

// Exceptions
const char * PmergeMe::WrongToken::what() const throw()
{
	return "Error";
}