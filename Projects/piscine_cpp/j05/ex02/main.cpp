/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:51:08 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/10 20:00:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
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
		PresidentialPardonForm *formTest2 = new PresidentialPardonForm("trump");
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
