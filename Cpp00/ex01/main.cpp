/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:23:39 by tfournie          #+#    #+#             */
/*   Updated: 2025/11/28 14:24:09 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

std::string PhoneBook::print_field(std::string field)
{
    std::string str;
    str = field;
    str.resize(9);
    return str ;
    
}

void PhoneBook::search(void)
{
    int i = 0;
    std::cout << "     index|first name| last name| nick name|" << std::endl;
    while (i < nb_contact)
    {
        std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].idx << "|";
        if(contact_l[i].first_name.size() > 9){
            std::cout << print_field(contact_l[i].first_name) << ".|" ;
        }
        else
            std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].first_name << "|" ;
        if(contact_l[i].last_name.size() > 9){
            std::cout << print_field(contact_l[i].last_name) << ".|" ;
        }
        else
            std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].last_name << "|" ;
        if(contact_l[i].nick_name.size() > 9){
            std::cout << print_field(contact_l[i].nick_name) << ".|" << std::endl << std::endl;
        }
        else
            std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].nick_name << "|" << std::endl << std::endl;
        i++;
    }
}



int main() 
{
    
    PhoneBook PhoneBook;
    std::string command;
    int i = 0;
    
    while(1){
        std::cout << "Write ADD or SEARCH or EXIT" << std::endl;
        
        std::cin >> command;
        if (command == "ADD")
        {
            Contact contact;
            contact.idx = i;
            std::cout << "First name?\n-";
            std::cin >> contact.first_name;
            std::cout << "last_name?\n-";
            std::cin >> contact.last_name;
            std::cout << "nick_name?\n-";
            std::cin >> contact.nick_name;
            std::cout << "phone_number?\n-";
            std::cin >> contact.phone_number;
            std::cout << "darkest secret?\n-";
            std::cin >> contact.secret;
            contact.idx = i;
            PhoneBook.contact_l[i] = contact;
            PhoneBook.nb_contact++;
            i++;
        }
        else if (command == "SEARCH")
        {
            int search_idx;
            int j = 0;
            PhoneBook.search();
            std::cout << "\nEnter an index?\n-";
            std::cin >> search_idx;
            while (j < PhoneBook.nb_contact)
            {
                if (search_idx == j)
                {
                    std::cout << "\nFirst name:" << PhoneBook.contact_l[j].first_name << std::endl;
                    std::cout << "Last name:" << PhoneBook.contact_l[j].last_name << std::endl;
                    std::cout << "Nick name:" << PhoneBook.contact_l[j].nick_name << std::endl;
                    std::cout << "Phone number:" << PhoneBook.contact_l[j].phone_number << std::endl;
                    std::cout << "Darkest secret:" << PhoneBook.contact_l[j].secret << std::endl << std::endl;
                }
                else
                    std::cout << "Wrong index!" << std::endl << std::endl;
                j++;
            }
        }
        else if (command == "EXIT")
            return (0);
    }
    
    return (0);
}
