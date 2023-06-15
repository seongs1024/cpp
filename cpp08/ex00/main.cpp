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
    if (easyfind(vec, 7) != vec.end())
        std::cout << "7 is found" << std::endl;
    if (easyfind(vec, 42) != vec.end())
        std::cout << "42 is found" << std::endl;
    if (easyfind(deq, 7) != deq.end())
        std::cout << "7 is found" << std::endl;
    if (easyfind(deq, 42) != deq.end())
        std::cout << "42 is found" << std::endl;
    if (easyfind(list, 7) != list.end())
        std::cout << "7 is found" << std::endl;
    if (easyfind(list, 42) != list.end())
        std::cout << "42 is found" << std::endl;
    return 0;
}