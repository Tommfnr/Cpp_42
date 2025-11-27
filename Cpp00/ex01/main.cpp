/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:23:39 by tfournie          #+#    #+#             */
/*   Updated: 2025/11/27 19:32:47 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>


int main() 
{
    
    PhoneBook PhoneBook;
    std::string command;
    int i = 0;
    
    std::cout << "Write ADD or SEARCH or EXIT" << std::endl;
    while(1){
        
        std::cin >> command;
        // if (command == "")
        //     return (0);
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
            std::cout << "secret?\n-";
            std::cin >> contact.secret;
            i++;
            std::cout << "First name:" << contact.first_name << std::endl;
            std::cout << "last_name:" << contact.last_name << std::endl;
            std::cout << "nick_name:" << contact.nick_name << std::endl;
            std::cout << "phone_number:" << contact.phone_number << std::endl;
            std::cout << "secret:" << contact.secret << std::endl;
            std::cout << "idx:" << contact.idx << std::endl;
        }
        else if (command == "SEARCH")
        {
        }
        else if (command == "EXIT")
            return (0);
    }
    
    return (0);
}
