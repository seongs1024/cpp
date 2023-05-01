/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:04:05 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:04:27 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "Field.hpp"

Field::Field(): HEADER(NULL), _value() {}

Field::Field(const char* header, std::string value): HEADER(header), _value(value) {}

const char* Field::header() const
{
    return (this->HEADER);
}

const std::string& Field::value() const
{
    return (this->_value);
}

void Field::set_value(std::string value)
{
    size_t len = value.length();
    size_t i = 0;
    if (len <= 0)
        throw std::runtime_error("Empty string");
    for (; i < len; i++)
    {
        if (value[i] != ' ')
            break;
    }
    if (i == len)
        throw std::runtime_error("It contains only space");
    this->_value = value;
}

FirstNameField::FirstNameField(std::string value): Field("First Name", value) {}

LastNameField::LastNameField(std::string value): Field("Last Name", value) {}

NickNameField::NickNameField(std::string value): Field("Nick Name", value) {}

PhoneNumberField::PhoneNumberField(std::string value): Field("Phone Number", value) {}

DarkestSecretField::DarkestSecretField(std::string value): Field("Darkest Secret", value) {}
