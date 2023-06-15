#include "PmergeMe.hpp"

#include <iostream>
#include <algorithm>

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

size_t PmergeMe::size() const
{
	return _size;
}

PmergeMe::Container1 & PmergeMe::con1()
{
	return _con1;
}

PmergeMe::Container2 & PmergeMe::con2()
{
	return _con2;
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

void PmergeMe::sortCon1(Container1 & con)
{
	std::sort(con.begin(), con.end());
}

void PmergeMe::sortCon2(Container2 & con)
{
	(void)con;
}


// Exceptions
const char * PmergeMe::WrongToken::what() const throw()
{
	return "Error";
}