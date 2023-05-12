/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat copy.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:01 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/12 15:32:06 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "IAnimal.hpp"

class Cat: public virtual IAnimal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat & operator=( Cat const & rhs );

		void makeSound(void) const;

	private:
		Brain * _brain;
};

#endif