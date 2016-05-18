/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:48:32 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/13 19:25:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setFirst_name(std::string str)
{
	this->first_name = str;
}

std::string	Contact::getFirst_name(void)
{
	return this->first_name;
}

void	Contact::setLast_name(std::string str)
{
	this->last_name = str;
}

std::string	Contact::getLast_name(void)
{
	return this->last_name;
}

void	Contact::setNickname(std::string str)
{
	this->nickname = str;
}

std::string	Contact::getNickname(void)
{
	return this->nickname;
}

void	Contact::setLogin(std::string str)
{
	this->login = str;
}

std::string	Contact::getLogin(void)
{
	return this->login;
}

void	Contact::setPostal_adress(std::string str)
{
	this->postal_adress = str;
}

std::string	Contact::getPostal_adress(void)
{
	return this->postal_adress;
}

void	Contact::setEmail_adress(std::string str)
{
	this->email_adress = str;
}

std::string	Contact::getEmail_adress(void)
{
	return this->email_adress;
}

void	Contact::setPhone_number(std::string str)
{
	this->phone_number = str;
}

std::string	Contact::getPhone_number(void)
{
	return this->phone_number;
}

void	Contact::setBirthday_date(std::string str)
{
	this->birthday_date = str;
}

std::string	Contact::getBirthday_date(void)
{
	return this->birthday_date;
}

void	Contact::setFavorite_meal(std::string str)
{
	this->favorite_meal = str;
}

std::string	Contact::getFavorite_meal(void)
{
	return this->favorite_meal;
}

void	Contact::setUnderware_color(std::string str)
{
	this->underware_color = str;
}

std::string	Contact::getUnderware_color(void)
{
	return this->underware_color;
}

void	Contact::setDarkest_secret(std::string str)
{
	this->darkest_secret = str;
}

std::string	Contact::getDarkest_secret(void)
{
	return this->darkest_secret;
}

void		Contact::add(void)
{
	std::string	command;

	std::cout << "\033[92mFirst Name : \033[94m";
	std::cin >> command;
	this->setFirst_name(command);

	std::cout << "\033[92mLast Name : \033[94m";
	std::cin >> command;
	this->setLast_name(command);

	std::cout << "\033[92mNickname : \033[94m";
	std::cin >> command;
	this->setNickname(command);

	std::cout << "\033[92mLogin : \033[94m";
	std::cin >> command;
	this->setLogin(command);

	std::cout << "\033[92mPostal Adress : \033[94m";
	std::cin >> command;
	this->setPostal_adress(command);

	std::cout << "\033[92mEmail Adress : \033[94m";
	std::cin >> command;
	this->setEmail_adress(command);

	std::cout << "\033[92mPhone Number : \033[94m";
	std::cin >> command;
	this->setPhone_number(command);

	std::cout << "\033[92mBirthday Date : \033[94m";
	std::cin >> command;
	this->setBirthday_date(command);

	std::cout << "\033[92mFavourite Meal : \033[94m";
	std::cin >> command;
	this->setFavorite_meal(command);

	std::cout << "\033[92mUnderware Color : \033[94m";
	std::cin >> command;
	this->setUnderware_color(command);

	std::cout << "\033[92mDarkest Secret : \033[94m";
	std::cin >> command;
	this->setDarkest_secret(command);
}

void		Contact::put_string(std::string str)
{
	for (int i = 0; i < 10 - (int)str.length(); i++)
		std::cout << " ";
	if (str.length() > 10)
	{
		str.resize(9);
		std::cout << str << ".";
	}
	else
		std::cout << str;
}

void		Contact::search_tab(int i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	first_name = this->getFirst_name();
	last_name = this->getLast_name();
	nickname = this->getNickname();
	std::cout << "         " << i << "|";
	put_string(first_name);
	std::cout << "|";
	put_string(last_name);
	std::cout << "|";
	put_string(nickname);
	std::cout << std::endl;
}

void		Contact::search(void)
{
	std::cout << "\033[92mFirst Name : \033[94m" << this->getFirst_name() << std::endl;
	std::cout << "\033[92mLast Name : \033[94m" << this->getLast_name() << std::endl;
	std::cout << "\033[92mNickname : \033[94m" << this->getNickname() << std::endl;
	std::cout << "\033[92mLogin : \033[94m" << this->getLogin() << std::endl;
	std::cout << "\033[92mPostal Adress : \033[94m" << this->getPostal_adress() << std::endl;
	std::cout << "\033[92mEmail Adress : \033[94m" << this->getEmail_adress() << std::endl;
	std::cout << "\033[92mPhone Number : \033[94m" << this->getPhone_number() << std::endl;
	std::cout << "\033[92mBirthday Date : \033[94m" << this->getBirthday_date() << std::endl;
	std::cout << "\033[92mFavourite Meal : \033[94m" << this->getFavorite_meal() << std::endl;
	std::cout << "\033[92mUnderware Color : \033[94m" << this->getUnderware_color() << std::endl;
	std::cout << "\033[92mDarkest Secret : \033[94m" << this->getDarkest_secret() << std::endl;
}
