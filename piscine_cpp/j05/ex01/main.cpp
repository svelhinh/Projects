/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:54:05 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 12:21:28 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	Bureaucrat *yo = new Bureaucrat("yo", 150);
	Form *form = new Form("toto", 120, 120);

	std::cout << "\033[33m" << *form << std::endl;
	std::cout << "\033[36m";
	try
	{
		yo->signForm(form);
		std::cout << "\033[33m" << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[36m" << *yo << std::endl;
	for (int i = 0; i < 148; i++)
	{
		try
		{
			yo->inc();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[36m" << *yo << std::endl;

	std::cout << "\033[33m" << *form << std::endl;
	std::cout << "\033[36m";
	try
	{
		yo->signForm(form);
		std::cout << "\033[33m" << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete yo;
	delete form;
	return 0;
}
