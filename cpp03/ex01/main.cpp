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