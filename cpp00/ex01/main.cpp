/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:04:10 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:04:27 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

void print_help()
{
    std::cout
        << "== Phone Book ==\n"
        << "You can type a command:\n"
        << "- ADD: save a contact\n"
        << "- SEARCH: display a specific contact\n"
        << "- EXIT: bye~ bye~" << std::endl;
}

int main() {
    print_help();
    PhoneBook pb = PhoneBook();
    while (true)
    {
        std::cout << "CMD: ";
        std::string cmd;
        std::getline(std::cin, cmd);
        if (std::cin.fail())
        {
            std::cerr << "::Aborted to input a command, EXIT!" << std::endl;
            std::exit(0);
        }
        for (size_t i = 0; i < cmd.length(); i++)
        {
            cmd[i] = toupper(cmd[i]);
        }
        if (cmd == "ADD")
        {
            pb.add();
            print_help();
        }
        else if (cmd == "SEARCH")
        {
            pb.search();
            print_help();
        }
        else if (cmd == "EXIT")
            std::exit(0);
        else
            std::cerr << "::Invalid command!" << std::endl;
    }
    return (0);
}
