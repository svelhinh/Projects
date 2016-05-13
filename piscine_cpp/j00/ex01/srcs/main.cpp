/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:26:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/13 19:30:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

int		main(void)
{
	std::string command;
    Contact contacts;
    // int i;

    // i = 0;
	while (command.compare("EXIT"))
    {
        std::cout << "Choose a command (ADD, SEARCH, EXIT) : ";
    	std::cin >> command;
        if (!command.compare("ADD"))
        {
            contacts.setFirst_name("yo");
            std::cout << contacts.getFirst_name() << std::endl;
        }
    }
	return 0;
}
