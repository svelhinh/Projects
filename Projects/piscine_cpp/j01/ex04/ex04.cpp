/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:04:53 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 15:07:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string	hi("HI THIS IS BRAIN");
	std::string *hi_pt = &hi;
	std::string &hi_ref = hi;

	std::cout << *hi_pt << std::endl;
	std::cout << hi_ref << std::endl;

	return 0;
}
