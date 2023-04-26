/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:19:43 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:43:10 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    std::cout << "== ZOMEBIE ==" << std::endl;
    Zombie zomb("zomb");

    std::cout << "== newZombie ==" << std::endl;
    Zombie* x = newZombie("X");
    delete x;

    std::cout << "== randomChump ==" << std::endl;
    randomChump("Y");

    std::cout << "== Closing Phase ==" << std::endl;
}