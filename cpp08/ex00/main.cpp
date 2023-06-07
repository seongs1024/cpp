#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main( void ) {
    int arr[] =  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec(arr, arr + 10);
    std::deque<int> deq(arr, arr + 10);
    std::list<int> list(arr, arr + 10);
    try
    {
        if (easyfind(vec, 7))
            std::cout << "7 is found" << std::endl;
        if (easyfind(vec, 42))
            std::cout << "42 is found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        if (easyfind(deq, 7))
            std::cout << "7 is found" << std::endl;
        if (easyfind(deq, 42))
            std::cout << "42 is found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        if (easyfind(list, 7))
            std::cout << "7 is found" << std::endl;
        if (easyfind(list, 42))
            std::cout << "42 is found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}