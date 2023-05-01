/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:03 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 13:59:25 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public virtual Animal
{
	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog & operator=( Dog const & rhs );

		void makeSound(void) const;
};

#endif