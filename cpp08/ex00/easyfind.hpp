#pragma once
#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(T & a, int b)
{
    return std::find(a.begin(), a.end(), b);
}