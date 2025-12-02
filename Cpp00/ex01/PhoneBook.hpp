/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:13:39 by tfournie          #+#    #+#             */
/*   Updated: 2025/12/02 12:53:36 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    
    public:
    
        Contact contact_l[8];
        
        PhoneBook(void);
        void search();
        std::string print_field(std::string field);
        std::string readField(const std::string &prompt);

        int nb_contact;
};

#endif