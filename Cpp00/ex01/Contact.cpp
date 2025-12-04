/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:00:46 by tfournie          #+#    #+#             */
/*   Updated: 2025/12/03 11:31:06 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string Contact::GetFirstName(void)
{
    return (_first_name); 
} 
void Contact::SetFirstName(std::string str) 
{
    _first_name = str; 
}


std::string Contact::GetLastName(void)
{
    return (_last_name); 
} 
void Contact::SetLastName(std::string str) 
{
    _last_name = str; 
}


std::string Contact::GetNickName(void)
{
    return (_nick_name); 
} 
void Contact::SetNickName(std::string str) 
{
    _nick_name = str; 
}


std::string Contact::GetPhoneN(void)
{
    return (_phone_number); 
} 
void Contact::SetPhoneN(std::string str) 
{
    _phone_number = str; 
}


std::string Contact::Getsecret(void)
{
    return (_secret); 
} 
void Contact::Setsecret(std::string str) 
{
    _secret = str; 
}
