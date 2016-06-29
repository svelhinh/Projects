/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:54:05 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/27 14:17:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int		main(void)
{
	Bureaucrat *yo = new Bureaucrat("yo", 150);
	Intern	intern;
	Form	*form = intern.makeForm("shrubberry creation", "Bender");
	Form	*form2 = intern.makeForm("robotomy request", "home");
	Form	*form3 = intern.makeForm("presidential pardon", "toto");
	Form	*form4 = intern.makeForm("shgiuhsdiuh", "toto2");

	(void)form4;
	std::cout << *form << std::endl;
	try
	{
		yo->signForm(form);
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << *yo << std::endl;
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
	std::cout << *yo << std::endl;

	std::cout << *form << std::endl;
	try
	{
		yo->signForm(form);
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		yo->signForm(form2);
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		yo->signForm(form3);
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	yo->executeForm(*form);
	yo->executeForm(*form2);
	yo->executeForm(*form3);


	delete yo;
	delete form;
	delete form2;
	delete form3;
	return 0;
}
