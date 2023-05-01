/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:04:24 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 10:04:27 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define NUM_CONTACTS (8)

# include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        void add();
        void search();
        
    private:
        size_t _saved_contacts;
        size_t _idx;
        Contact _contacts[NUM_CONTACTS];
        void display_all_contacts();
        void dispaly_contact(size_t idx);
};

#endif
