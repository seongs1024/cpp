#pragma once
#include <iostream>

template<typename T>
void iter(T arr[], int size, void (*f)(T &))
{
    if (arr == 0)
        return;
    try
    {
        for (int i = 0; i < size; i++)
            f(arr[i]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}