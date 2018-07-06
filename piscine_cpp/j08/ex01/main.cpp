/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:05:15 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/13 15:50:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int	main()
{
	srand(time(NULL));
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span test(100);
	Span test2(10000);
	std::vector<int> testList;

	try
	{
		std::cout << "shortest: " << test.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	for (int i = 0; i <= 100; i++)
	{
		try
		{
			int random = rand() * 10000.f / RAND_MAX;
			test.addNumber(random);
			std::cout << random << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	try
	{
		std::cout << "shortest: " << test.shortestSpan() << std::endl;
		std::cout << "longest: " << test.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	testList.push_back(rand() * 10000.f / RAND_MAX);

	try
	{
		test2.addNumber(testList);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
