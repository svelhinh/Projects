/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:51:08 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/10 19:13:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat *toto = new Bureaucrat("toto", 170);
		delete toto;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *tata = new Bureaucrat("tata", -150);
		delete tata;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat *bob = new Bureaucrat("bob", 149);

	std::cout << *bob << std::endl;
	try
	{
		bob->dec();
		std::cout << *bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		bob->dec();
		std::cout << *bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (int i = 0; i < 148; i++)
	{
		try
		{
			bob->inc();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << *bob << std::endl;
	try
	{
		bob->inc();
		std::cout << *bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bob->inc();
		std::cout << *bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form *formTest = new Form("test", 170, -1);
		delete formTest;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat *jim = new Bureaucrat("jim", 1);

	try
	{
		Form *formTest2 = new Form("test2", 2, 50);
		jim->signForm(formTest2);
		jim->dec();
		jim->dec();
		std::cout << *jim << std::endl;
		jim->signForm(formTest2);
		delete formTest2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete bob;
	delete jim;
	return 0;
}
