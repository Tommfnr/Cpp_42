/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:23:39 by tfournie          #+#    #+#             */
/*   Updated: 2025/11/28 15:35:54 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook(void){
    
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
    std::cout << "     index|first name| last name| nick name|" << std::endl;
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



int main() 
{
    
    PhoneBook pb;
    std::string command;
    std::string str;
    int i = 0;
    
    while(1){
        std::cout << "Write ADD or SEARCH or EXIT" << std::endl;
        
        std::cin >> command;
        Contact contact;
        if (command == "ADD")
        {
            contact.idx = i;
            std::cout << "First name?\n-";
            std::cin >> str;
            contact.SetFirstName(str);
            std::cout << "last_name?\n-";
            std::cin >> str;
            contact.SetLastName(str);
            std::cout << "nick_name?\n-";
            std::cin >> str;
            contact.SetNickName(str);
            std::cout << "phone_number?\n-";
            std::cin >> str;
            contact.SetPhoneN(str);
            std::cout << "darkest secret?\n-";
            std::cin >> str;
            contact.Setsecret(str);
            contact.idx = i;
            pb.contact_l[i] = contact;
            pb.nb_contact++;
            i++;
        }
        else if (command == "SEARCH")
        {
            int search_idx;
            int j = 0;
            pb.search();
            std::cout << "\nEnter an index?\n-";
            std::cin >> search_idx;
            while (j < pb.nb_contact)
            {
                if (search_idx == j)
                {
                    std::cout << "\nFirst name:" << pb.contact_l[i].GetFirstName() << std::endl;
                    std::cout << "Last name:" << pb.contact_l[j].GetLastName() << std::endl;
                    std::cout << "Nick name:" << pb.contact_l[j].GetNickName() << std::endl;
                    std::cout << "Phone number:" << pb.contact_l[j].GetPhoneN() << std::endl;
                    std::cout << "Darkest secret:" << pb.contact_l[j].Getsecret() << std::endl << std::endl;
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
