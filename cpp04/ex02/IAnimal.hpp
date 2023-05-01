/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:00 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 16:53:20 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_ANIMAL_HPP
# define I_ANIMAL_HPP

# include <string>
# include "Brain.hpp"

class IAnimal
{
	public:
		IAnimal(void);
		IAnimal(std::string type);
		IAnimal(IAnimal const & src);
		virtual ~IAnimal(void);

		IAnimal & operator=( IAnimal const & rhs );

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

	protected:
		std::string _type;

	private:
		Brain *	_brain;
};

#endif