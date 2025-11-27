/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:06:20 by tfournie          #+#    #+#             */
/*   Updated: 2025/11/27 15:22:22 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string    buff;
    int i = 1;
    
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        while(i < ac)
        {
            buff.append(av[i]);
            i++;
        }
        int len = buff.size();
        for(int i = 0; i < len; i++)
            buff[i] = std::toupper(static_cast <unsigned char> (buff[i]));
        std::cout << buff << std::endl; 
    }
}
