/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:00:54 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 13:01:47 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon* _weapon;
public:
    HumanB(std::string name);
    void attack() const;
    void setWeapon(Weapon& weapon);
};

#endif
