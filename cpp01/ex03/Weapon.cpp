/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:00:59 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 12:13:08 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

const std::string &Weapon::getType() const
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
