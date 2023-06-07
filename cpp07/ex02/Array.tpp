#pragma once
#include <stdexcept>

// Constructors
template<typename T>
Array<T>::Array(): _data(new T[0]), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n): _data(new T[n]), _size(n)
{
}

template<typename T>
Array<T>::Array(const Array<T> &copy): _data(new T[copy.size()]), _size(copy.size())
{
	for (size_t i = 0; i < _size; i++)
		_data[i] = copy._data[i];
}

// Destructor
template<typename T>
Array<T>::~Array()
{
	delete[] _data;
}


// Operators
template<typename T>
Array<T> & Array<T>::operator=(const Array<T> &assign)
{
	if (this != &assign)
	{
		delete[] _data;
		_size = assign.size();
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = assign._data[i];
	}
	return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw std::out_of_range("Out of range");
	return _data[i];
}

// Getters / Setters
template<typename T>
size_t Array<T>::size() const
{
	return _size;
}
