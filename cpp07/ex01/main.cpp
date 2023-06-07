#include "iter.hpp"
#include <iostream>

template<typename T>
void f(T & e)
{
    std::cout << e << std::endl;
}

int main( void ) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
    double arr2[] = {.0, .1, .2, .3, .4, .5, .6, .7, .8, .9, };
    iter(arr, 10, &f);
    iter(arr, 15, &f);
    iter(arr2, 10, &f);
    iter(arr2, 15, &f);
}