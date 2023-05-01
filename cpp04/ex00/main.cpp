#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;

    const WrongAnimal* meta_w = new WrongAnimal();
    const WrongAnimal* j_w = new WrongDog();
    const WrongAnimal* i_w = new WrongCat();
    std::cout << j_w->getType() << " " << std::endl;
    std::cout << i_w->getType() << " " << std::endl;
    i_w->makeSound(); //will output the cat sound!
    j_w->makeSound();
    meta_w->makeSound();
    delete i_w;
    delete j_w;
    delete meta_w;
    return 0;
}
