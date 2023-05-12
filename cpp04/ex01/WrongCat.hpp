/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:08 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 13:59:20 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);

		WrongCat & operator=( WrongCat const & rhs );

		void makeSound(void) const;
};

#endif