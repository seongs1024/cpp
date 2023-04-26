/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:00:55 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 12:17:58 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {}

void HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = weapon;
}
