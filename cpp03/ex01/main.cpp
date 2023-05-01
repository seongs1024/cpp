/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:54:57 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:54:58 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap a("xx");
    ClapTrap b("oo");

    a.attack("yy");

    a.takeDamage(9);
    a.beRepaired(9);

    b.takeDamage(10);
    b.beRepaired(10);

    ScavTrap c("11");
    c.guardGate();
    c.attack("zz");
    c.takeDamage(100);
    c.beRepaired(100);
}