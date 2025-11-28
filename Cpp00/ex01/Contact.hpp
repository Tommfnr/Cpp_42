/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:45:46 by tfournie          #+#    #+#             */
/*   Updated: 2025/11/28 15:34:54 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
    
    private:
    
        std::string     _first_name;
        std::string     _last_name;
        std::string     _nick_name;
        std::string     _phone_number;
        std::string     _secret;
    
    public:
    
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetPhoneN();
        std::string Getsecret();

        void SetFirstName(std::string); 
        void SetLastName(std::string); 
        void SetNickName(std::string); 
        void SetPhoneN(std::string); 
        void Setsecret(std::string);

        
        int             idx;

};

#endif