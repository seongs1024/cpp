#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie x = Zombie(name);
    x.announce();
}