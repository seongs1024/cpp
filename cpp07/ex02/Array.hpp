#pragma once

#include <iostream>

template<typename T>
class Array
{
	public:
		// Constructors
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		
		// Destructor
		~Array();
		
		// Operators
		Array & operator=(const Array &assign);
		T & operator[](unsigned int i) const;
		
		// Getters / Setters
		size_t size() const;
		
	private:
		T * _data;
		size_t _size;
		
};

#include "Array.tpp"