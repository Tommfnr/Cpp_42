/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:45:46 by tfournie          #+#    #+#             */
/*   Updated: 2025/11/27 19:24:52 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
    
    private:

    
    public:
    
        std::string     first_name;
        std::string     last_name;
        std::string     nick_name;
        std::string     phone_number;
        std::string     secret;
        int             idx;

};

#endif