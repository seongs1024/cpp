/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:19:43 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 11:33:37 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 5;
    
    std::cout << "== HORDE ==" << std::endl;
    Zombie* horde = zombieHorde(N, "papa");
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;

    std::cout << "== Closing Phase ==" << std::endl;
}