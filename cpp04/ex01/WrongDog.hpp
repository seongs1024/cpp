/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:10 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 13:59:18 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
	public:
		WrongDog(void);
		WrongDog(WrongDog const & src);
		~WrongDog(void);

		WrongDog & operator=( WrongDog const & rhs );

		void makeSound(void) const;
};

#endif