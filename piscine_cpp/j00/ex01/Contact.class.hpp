/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:20:09 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 14:11:06 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>
# include <iomanip>

class	Contact
{
public:
	Contact(void);
	~Contact(void);

	void	addContact();
	void	showContactNoDetails(int id);
	void	showContactDetails();

private:
	std::string	firstName, lastName, nickname, login, postalAddress,
				emailAddress, phoneNumber, birthdayDate, favoriteMeal,
				underwearColor, darkestSecret;
};

#endif
