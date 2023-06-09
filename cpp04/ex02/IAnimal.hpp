/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:00 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/12 15:40:32 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_ANIMAL_HPP
# define I_ANIMAL_HPP

# include <string>

class IAnimal
{
	public:
		virtual ~IAnimal(void);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

	protected:
		IAnimal(std::string type);
		IAnimal(IAnimal const & src);
		IAnimal & operator=( IAnimal const & rhs );

		std::string _type;

	private:
		IAnimal(void);
};

#endif