/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:00 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 15:26:59 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define NUM_IDEAS (100)

# include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain & operator=( Brain const & rhs );
	private:
		std::string _ideas[NUM_IDEAS];

};

#endif