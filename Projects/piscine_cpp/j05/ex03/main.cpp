/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:51:08 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 11:53:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	srand(time(NULL));

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

	Bureaucrat *jim = new Bureaucrat("jim", 135);
	Bureaucrat *robert = new Bureaucrat("robert", 142);

	try
	{
		ShrubberyCreationForm *formTest2 = new ShrubberyCreationForm("home");
		jim->signForm(formTest2);
		jim->executeForm(*formTest2);
		robert->executeForm(*formTest2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat *toto = new Bureaucrat("toto", 12);

	try
	{
		RobotomyRequestForm *formTest2 = new RobotomyRequestForm("moon");
		std::cout << *toto << std::endl;
		toto->signForm(formTest2);
		toto->executeForm(*formTest2);
		delete formTest2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat *tata = new Bureaucrat("tata", 3);

	try
	{
		Intern *bibi = new Intern();
		Form *formTest2 = bibi->makeForm("presidential pardon", "trump");
		Form *formTest3 = bibi->makeForm("yoyo", "bibi");
		if (formTest2 == NULL)
			std::cout << "formTest2 is NULL" << std::endl;
		else
			std::cout << *formTest2 << std::endl;
		if (formTest3 == NULL)
			std::cout << "formTest3 is NULL" << std::endl;
		else
			std::cout << *formTest3 << std::endl;
		std::cout << *tata << std::endl;
		tata->signForm(formTest2);
		tata->executeForm(*formTest2);
		delete formTest2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete bob;
	delete toto;
	delete jim;
	delete robert;
	return 0;
}
