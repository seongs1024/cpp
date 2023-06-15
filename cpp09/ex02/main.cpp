#include <iostream>
#include "PmergeMe.hpp"

/// @ref https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
int main(int argc, char *argv[]) {
	if (argc < 2 || argv == NULL) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pm(argc - 1);
		for (int i = 1; i < argc; i++)
		{
			pm.push(argv[i]);
		}
		std::cout << "vec: ";
		pm.printCon1();
		std::cout << std::endl;
		std::cout << "list: ";
		pm.printCon2();
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}