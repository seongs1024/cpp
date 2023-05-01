/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:06 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 13:59:22 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal(void);

		WrongAnimal & operator=( WrongAnimal const & rhs );

		void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string _type;

	private:
};

#endif