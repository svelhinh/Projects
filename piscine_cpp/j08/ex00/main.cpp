/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 13:09:25 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 13:31:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>

int		main(void)
{
	std::list<int> lst;

	lst.push_back(-3);
	lst.push_back(90);
	lst.push_back(134);
	try
	{
		easyfind(lst, -3);
		std::cout << "Found" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Not found" << std::endl;
	}
	return 0;
}
