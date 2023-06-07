#include "Span.hpp"
#include <algorithm>
#include <iterator>

// Constructors
Span::Span(unsigned int n): _capa(n), _shortest_span(-1)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}


// Destructor
Span::~Span()
{
}


// Operators
Span & Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		_capa = assign._capa;
		_list = assign._list;
		_shortest_span = assign._shortest_span;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (_list.size() >= _capa)
		throw OverCapacityException();
	std::list<int>::iterator pos = std::lower_bound(_list.begin(), _list.end(), num);
	std::list<int>::iterator iter = _list.insert(pos, num);
	if (iter != _list.begin())
	{
		int left_span = *iter - *next(iter, -1);
		if (_shortest_span < 0 || _shortest_span > left_span)
			_shortest_span = left_span;
	}
	if (next(iter, 1) != _list.end())
	{
		int right_span = *next(iter, 1) - *iter;
		if (_shortest_span < 0 || _shortest_span > right_span)
			_shortest_span = right_span;
	}
}

int Span::shortestSpan()
{
	if (_list.size() < 2)
		throw NoSpanFoundException();
    return _shortest_span;
}

int Span::longestSpan()
{
	if (_list.size() < 2)
		throw NoSpanFoundException();
    return *_list.rbegin() - *_list.begin();
}

std::list<int>::iterator Span::next(std::list<int>::iterator iter, int n)
{
	std::advance(iter, n);
    return iter;
}

// Exceptions
const char * Span::OverCapacityException::what() const throw()
{
	return "Adding new one is over the capacity";
}
const char * Span::NoSpanFoundException::what() const throw()
{
	return "No span can be found";
}
