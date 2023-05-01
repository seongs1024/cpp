/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:04 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 16:56:14 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "IAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


#define ANIMALS_HALF (1)

int main()
{
    // IAnimal ani;
    
    IAnimal* j = new Dog();
    IAnimal* i = new Cat();
    
    delete i;
    delete j;

    std::cout << "-------" << std::endl;

    IAnimal * animals[2 * ANIMALS_HALF];
    for (size_t i = 0; i < ANIMALS_HALF; i++) {
        animals[i] = new Dog();
        animals[ANIMALS_HALF + i] = new Cat();
    }
    for (size_t i = 0; i < 2 * ANIMALS_HALF; i++) {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
        delete animals[i];
    }

    std::cout << "+++++++" << std::endl;
    Dog coco;
    coco = Dog();
    
    return 0;
}
