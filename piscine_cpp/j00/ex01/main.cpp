/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:56:52 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 17:26:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

void	displayContacts(Contact contacts[], int nbContacts)
{
	std::string buf;

	std::cout << std::endl << std::setw(21) << "\033[92mIndex\033[94m|" << std::setw(21) << "\033[92mFirst Name\033[94m|" << std::setw(21) << "\033[92mLast Name\033[94m|" << std::setw(15) << "\033[92mNickname" << std::endl;
	for (int id = 0; id < nbContacts; id++)
		contacts[id].showContactNoDetails(id);
	std::cout << std::endl;
	std::cout << "\033[93mPlease type the id of the contact you want to display : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	if (buf.length() > 1 || buf[0] < '0' || buf[0] > '8' || buf[0] - '0' >= nbContacts)
		std::cout << std::endl << "\033[91mThis contact doesn't exists";
	else
	{
		std::cout << std::endl;
		contacts[buf[0] - '0'].showContactDetails();
	}
	std::cout << std::endl << std::endl;
}

int	main()
{
	Contact		contacts[8];
	int			nbContacts = 0;
	std::string buf;

	do
	{
		std::cout << "\033[93mDo you want to ADD or SEARCH a contact or EXIT phonebook ? : \033[94m";
		if (!std::getline (std::cin, buf))
			return 0;
		if (!buf.compare("ADD"))
		{
			if (nbContacts >= 8)
				std::cout << std::endl << "\033[91mYour phonebook is full" << std::endl << std::endl;
			else
			{
				std::cout << std::endl;
				contacts[nbContacts++].addContact();
				std::cout << std::endl;
			}
		}
		else if (!buf.compare("SEARCH"))
		{
			if (nbContacts)
				displayContacts(contacts, nbContacts);
		}
		else if (!buf.compare("EXIT"))
			return 0;
	}while (buf.compare("EXIT"));
	return 0;
}
