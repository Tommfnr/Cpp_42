/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:23:39 by tfournie          #+#    #+#             */
/*   Updated: 2025/12/02 12:59:16 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <stdlib.h>


PhoneBook::PhoneBook(void) : nb_contact(0){
    
}

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
    std::cout << "     index|first name| last name| nick name|" << std::endl << std::endl;
    while (i < nb_contact)
    {
        std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].idx << "|";
        if(contact_l[i].GetFirstName().size() > 9){
            std::cout << print_field(contact_l[i].GetFirstName()) << ".|" ;
        }
        else
            std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].GetFirstName() << "|" ;
        if(contact_l[i].GetLastName().size() > 9){
            std::cout << print_field(contact_l[i].GetLastName()) << ".|" ;
        }
        else
            std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].GetLastName() << "|" ;
        if(contact_l[i].GetNickName().size() > 9){
            std::cout << print_field(contact_l[i].GetNickName()) << ".|" << std::endl << std::endl;
        }
        else
            std::cout << std::setfill(' ') << std::setw(10) << contact_l[i].GetNickName() << "|" << std::endl << std::endl;
        i++;
    }
}

std::string readField(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt << "\n-";
        if (!std::getline(std::cin, input)) {
            std::cout << "EOF detected. Exiting.\n";
            exit(0);
        }
        if (!input.empty())
            return input;
        std::cout << "Empty field is not allowed!\n";
    }
}


int main() 
{
    
    PhoneBook pb;
    std::string command;
    int i = 0;
    
    while(1){
        std::cout << "Write ADD or SEARCH or EXIT" << std::endl;

        if (!(std::cin >> command)) {
            std::cout << "EOF detected. Exiting.\n";
            return 0;
        }
        if (command == "ADD")
        {
            if (i > 7)
                i = 0;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Contact contact;
            contact.idx = i;

            contact.SetFirstName(readField("First name?"));
            contact.SetLastName(readField("Last name?"));
            contact.SetNickName(readField("Nick name?"));
            contact.SetPhoneN(readField("Phone number?"));
            contact.Setsecret(readField("Darkest secret?"));

            pb.contact_l[i] = contact;

            if (pb.nb_contact < 8)
                pb.nb_contact++;

            i++;
        }
        else if (command == "SEARCH" && pb.nb_contact != 0)
        {
            int search_idx;
            int j = 0;
            pb.search();
            std::cout << "Enter an index?\n";
            std::cin >> search_idx;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input\n";
                continue;
            }
            if (search_idx < 0 || search_idx >= pb.nb_contact || search_idx >= 8) {
                std::cout << "Index invalide\n\n";
                continue;
            }
            while (j < pb.nb_contact)
            {
                if (j >= 8)
                    break;
                if (search_idx == j)
                {
                    std::cout << "\nFirst name:" << pb.contact_l[j].GetFirstName() << std::endl;
                    std::cout << "Last name:" << pb.contact_l[j].GetLastName() << std::endl;
                    std::cout << "Nick name:" << pb.contact_l[j].GetNickName() << std::endl;
                    std::cout << "Phone number:" << pb.contact_l[j].GetPhoneN() << std::endl;
                    std::cout << "Darkest secret:" << pb.contact_l[j].Getsecret() << std::endl << std::endl;
                    break;
                }
                j++;
            }
        }
        else if (command == "EXIT")
            return (0);
    }
    
    return (0);
}
