/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:26:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/14 17:58:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

int		main(void)
{
	std::string command, index;
    Contact contacts[8];
    int i = 0;

	while (command.compare("EXIT"))
    {
        std::cout << "\033[93mChoose a command (ADD, SEARCH, EXIT) : \033[94m";
    	std::cin >> command;
        if (!command.compare("ADD"))
        {
            if (i < 8)
            {
				contacts[i].add();
                i++;
            }
            else
                std::cout << "\033[91mYou can't have more than 8 contacts\033[0m" << std::endl;
        }
		if (!command.compare("SEARCH"))
		{
			if (i != 0)
			{
				std::cout << "     Index" << "|" << "First Name" << "|" << " Last Name" << "|" << "  Nickname" << std::endl;
				for (int j = 0; j < i; j++)
					contacts[j].search_tab(j);
                std::cout << "\033[93mPlease choose an index : \033[94m";
                std::cin >> index;
                if (index.length() == 1 && index[0] - '0' >= 0 && index[0] - '0' < i)
                    contacts[index[0] - '0'].search();
                else
                    std::cout << "\033[91mIndex must be an integer between 0 and " << i - 1 << "\033[0m" << std::endl;
			}
			else
				std::cout << "\033[91mYou have no contacts in your phonebook\033[0m" << std::endl;
		}
    }
	return 0;
}
