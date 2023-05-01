/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:54:44 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:54:45 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main() {
    ClapTrap a("xx");
    ClapTrap b("oo");

    a.attack("yy");

    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);
    
    a.takeDamage(9);
    a.beRepaired(9);

    a.takeDamage(9);
    a.beRepaired(9);

    b.takeDamage(10);
    b.beRepaired(10);
}