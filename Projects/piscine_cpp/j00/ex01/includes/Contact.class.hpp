/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:48:32 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/13 19:21:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>

class Contact
{
public:
	Contact(void);
	~Contact(void);

	void		setFirst_name(std::string str);
	std::string	getFirst_name(void);
	void		setLast_name(std::string str);
	std::string	getLast_name(void);
	void		setNickname(std::string str);
	std::string	getNickname(void);
	void		setLogin(std::string str);
	std::string	getLogin(void);
	void		setPostal_adress(std::string str);
	std::string	getPostal_adress(void);
	void		setEmail_adress(std::string str);
	std::string	getEmail_adress(void);
	void		setPhone_number(std::string str);
	std::string	getPhone_number(void);
	void		setBirthday_date(std::string str);
	std::string	getBirthday_date(void);
	void		setFavorite_meal(std::string str);
	std::string	getFavorite_meal(void);
	void		setUnderware_color(std::string str);
	std::string	getUnderware_color(void);
	void		setDarkest_secret(std::string str);
	std::string	getDarkest_secret(void);
	void		add(void);
	void		search(void);
	void		search_tab(int i);
	void		put_string(std::string str);

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_adress;
	std::string email_adress;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underware_color;
	std::string darkest_secret;
};
#endif
