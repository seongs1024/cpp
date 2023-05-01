/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:04:03 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:04:29 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "Contact.hpp"

Contact::Contact()
{
    this->_fields[0] = FirstNameField("");
    this->_fields[1] = LastNameField("");
    this->_fields[2] = NickNameField("");
    this->_fields[3] = PhoneNumberField("");
    this->_fields[4] = DarkestSecretField("");
}

Field& Contact::field(size_t idx)
{
    if (idx >= NUM_FIELDS)
        throw std::runtime_error("Indexing is out of range!");
    return (this->_fields[idx]);
}
