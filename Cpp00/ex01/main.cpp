/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:23:39 by tfournie          #+#    #+#             */
/*   Updated: 2025/12/03 11:49:55 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <stdlib.h>


PhoneBook::PhoneBook(void) : nb_contact(0) {}

std::string print_field(std::string field)
{
    std::string str;
    str = field;
    str.resize(9);
    return str ;
    
}

void PhoneBook::print_contact(void)
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

void PhoneBook::Search(void)
{
    if (nb_contact == 0)
        return ;
        
    int search_idx;
    int j = 0;
    
    print_contact();
    std::cout << "Enter an index?\n";
    std::cin >> search_idx;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input\n";
        return ;
    }
    
    if (search_idx < 0 || search_idx >= nb_contact || search_idx >= 8) {
        std::cout << "Index invalide\n\n";
        return ;
    }
    
    while (j < nb_contact)
    {
        if (j >= 8)
            break;
        if (search_idx == j)
        {
            std::cout << "\nFirst name:" << contact_l[j].GetFirstName() << std::endl;
            std::cout << "Last name:" << contact_l[j].GetLastName() << std::endl;
            std::cout << "Nick name:" << contact_l[j].GetNickName() << std::endl;
            std::cout << "Phone number:" << contact_l[j].GetPhoneN() << std::endl;
            std::cout << "Darkest secret:" << contact_l[j].Getsecret() << std::endl << std::endl;
            break;
        }
        j++;
    }
}

void PhoneBook::Add(void)
{
    int i = 0;
    
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

    contact_l[i] = contact;

    if (nb_contact < 8)
        nb_contact++;

    i++;
}




int main() 
{
    
    PhoneBook pb;
    std::string command;
        
    while(1){
        std::cout << "Write ADD or SEARCH or EXIT" << std::endl;

        if (!(std::cin >> command)) {
            std::cout << "EOF detected. Exiting.\n";
            return 0;
        }
        if (command == "ADD")
            pb.Add();
        else if (command == "SEARCH")
            pb.Search();
        else if (command == "EXIT")
            return (0);
    }
    
    return (0);
}
