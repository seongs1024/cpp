/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:04:07 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:04:27 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _saved_contacts(0), _idx(0) {};

void PhoneBook::add()
{
    std::cout << "++ New Contact ++" << std::endl;
    Contact contact = this->_contacts[this->_idx];
    size_t field_i = 0;
    while (field_i < NUM_FIELDS)
    {
        std::string value;
        std::cout << contact.field(field_i).header() << ": ";
        std::getline(std::cin, value);
        if (std::cin.fail())
        {
            std::cout << "::Aborted to ADD a contact!" << std::endl;
            std::exit(0);
        }
        try
        {
            contact.field(field_i).set_value(value);
            field_i++;
        }
        catch (const std::exception &e)
        {
            std::cerr << "::" << e.what() << std::endl;
        }
    }
    if (field_i == NUM_FIELDS)
    {
        this->_contacts[this->_idx] = contact;
        this->_idx = (this->_idx + 1) % NUM_CONTACTS;
        if (this->_saved_contacts != NUM_CONTACTS)
            this->_saved_contacts++;
        std::cout << "::Completed to add a contact" << std::endl;
    }
}

void PhoneBook::search()
{
    if (this->_saved_contacts == 0)
    {
        std::cout << "::No Contact!" << std::endl;
        return;
    }
    this->display_all_contacts();
    while (true)
    {
        std::cout << "Select index: ";
        std::string idx_s;
        std::getline(std::cin, idx_s);
        if (std::cin.fail())
        {
            std::cerr << "::Aborted to SELECT a contact!" << std::endl;
            std::exit(0);
        }
        size_t idx;
        if (!(std::istringstream(idx_s) >> idx) || idx_s.length() != 1 || idx >= this->_saved_contacts)
            std::cerr << "::Wrong indexing!" << std::endl;
        else
        {
            this->dispaly_contact(idx);
            break;
        }
    }

}

void PhoneBook::display_all_contacts()
{
    const size_t NUM_COLS = 3;
    const char* DELIMITER = "|";
    std::cout << DELIMITER << std::right << std::setw(10) << "Index" << DELIMITER;
    for (size_t i = 0; i < NUM_COLS; i++)
    {
        std::string str = std::string(this->_contacts[0].field(i).header()).substr(0, 11);
        if (str.length() > 10)
        {
            str.resize(10);
            str[9] = '.';
        }
        std::cout << std::right << std::setw(10) << str << DELIMITER;
    }
    std::cout << std::endl;
    for (size_t i = 0; i < this->_saved_contacts; i++)
    {
        std::cout << DELIMITER << std::right << std::setw(10) << i << DELIMITER;
        for (size_t j = 0; j < NUM_COLS; j++)
        {
            std::string str = this->_contacts[i].field(j).value().substr(0, 11);
            if (str.length() > 10)
            {
                str.resize(10);
                str[9] = '.';
            }
            std::cout << std::right << std::setw(10) << str << DELIMITER;
        }
        std::cout << std::endl;
    }
}

void PhoneBook::dispaly_contact(size_t idx)
{
    std::cout << "** Contact Information **" << std::endl;
    for (size_t i = 0; i < NUM_FIELDS; i++)
    {
        std::cout
            << "- " << this->_contacts[idx].field(i).header() << ": "
            << this->_contacts[idx].field(i).value() << std::endl;
    }
}
