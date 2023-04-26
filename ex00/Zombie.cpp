/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:05 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:34:22 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
    std::cout << "Summoned a zomebie(" << this->_name << ")." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << ": KrrrrrrrrrrrrrrrrrA!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
