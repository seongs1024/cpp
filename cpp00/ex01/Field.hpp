/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:04:21 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:04:27 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_HPP
# define FIELD_HPP

# include <string>

class Field
{
    public:
        Field();
        Field(const char* header, std::string value);
        const char* header() const;
        const std::string& value() const;
        void set_value(std::string value);

    private:
        const char* HEADER;
        std::string _value;
};

class FirstNameField: public virtual Field
{
    public:
        FirstNameField(std::string value);
};

class LastNameField: public virtual Field
{
    public:
        LastNameField(std::string value);
};

class NickNameField: public virtual Field
{
    public:
        NickNameField(std::string value);
};

class PhoneNumberField: public virtual Field
{
    public:
        PhoneNumberField(std::string value);
};

class DarkestSecretField: public virtual Field
{
    public:
        DarkestSecretField(std::string value);
};

#endif
