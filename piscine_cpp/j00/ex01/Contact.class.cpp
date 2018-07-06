/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:20:11 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 17:24:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::addContact()
{
	std::string	buf;

	std::cout << "\033[92mFirst Name : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->firstName = buf;

	std::cout << "\033[92mLast Name : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->lastName = buf;

	std::cout << "\033[92mNickname : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->nickname = buf;

	std::cout << "\033[92mLogin : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->login = buf;

	std::cout << "\033[92mPostal Address : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->postalAddress = buf;

	std::cout << "\033[92mEmail Address : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->emailAddress = buf;

	std::cout << "\033[92mPhone Number : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->phoneNumber = buf;

	std::cout << "\033[92mBirthday Date : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->birthdayDate = buf;

	std::cout << "\033[92mFavorite Meal : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->favoriteMeal = buf;

	std::cout << "\033[92mUnderwear Color : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->underwearColor = buf;

	std::cout << "\033[92mDarkest Secret : \033[94m";
	if (!std::getline (std::cin, buf))
		std::exit(0);
	this->darkestSecret = buf;
}

void	Contact::showContactNoDetails(int id)
{
	std::cout << std::setw(10) << id << "\033[94m|\033[92m";
	if (this->firstName.length() < 10)
		std::cout << std::setw(10) << this->firstName;
	else
		std::cout << this->firstName.substr(0,9) << ".";
	std::cout << "\033[94m|\033[92m";

	if (this->lastName.length() < 10)
		std::cout << std::setw(10) << this->lastName;
	else
		std::cout << this->lastName.substr(0,9) << ".";
	std::cout << "\033[94m|\033[92m";

	if (this->nickname.length() < 10)
		std::cout << std::setw(10) << this->nickname;
	else
		std::cout << this->nickname.substr(0,9) << ".";

	std::cout << std::endl;
}

void	Contact::showContactDetails()
{
	std::cout << "\033[92mFirst Name : \033[94m" << this->firstName << std::endl
	<< "\033[92mLast Name : \033[94m" << this->lastName << std::endl
	<< "\033[92mNickname : \033[94m" << this->nickname << std::endl
	<< "\033[92mLogin : \033[94m" << this->login << std::endl
	<< "\033[92mPostal Address : \033[94m" << this->postalAddress << std::endl
	<< "\033[92mEmail Address : \033[94m" << this->emailAddress << std::endl
	<< "\033[92mPhone Number : \033[94m" << this->phoneNumber << std::endl
	<< "\033[92mBirthday Date : \033[94m" << this->birthdayDate << std::endl
	<< "\033[92mFavorite Meal : \033[94m" << this->favoriteMeal << std::endl
	<< "\033[92mUnderwear Color : \033[94m" << this->underwearColor << std::endl
	<< "\033[92mDarkest Secret : \033[94m" << this->darkestSecret;
}
