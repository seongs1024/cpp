#include <iostream>
#include "BitcoinExchange.hpp"

#define PRICE_DB_PATH ("data.csv")

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: " << BitcoinExchange::FileOpenException().what() << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange(PRICE_DB_PATH, argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}