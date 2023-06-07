#pragma once
#include <algorithm>
#include <exception>

template<typename T>
bool easyfind(T & a, int b)
{
    if (std::find(a.begin(), a.end(), b) != a.end())
        return true;
    else
        throw std::runtime_error("No occurrence!");
}