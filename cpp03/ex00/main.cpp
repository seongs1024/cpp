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