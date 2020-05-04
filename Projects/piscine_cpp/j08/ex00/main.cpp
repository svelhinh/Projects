/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:55:22 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/13 12:03:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>

int	main()
{
	std::list<int>	intList;
	int				value = 20;
	int				value2 = 0;

	intList.push_back(15);
	intList.push_back(20);
	intList.push_back(30);
	intList.push_back(12);

	try
	{
		easyfind(intList, value);
		std::cout << value << " found in container intList" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << ", " << value << " not found in container intList" << std::endl;
	}

	try
	{
		easyfind(intList, value2);
		std::cout << value2 << " found in container intList" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << ", " << value2 << " not found in container intList" << std::endl;
	}
	return 0;
}
