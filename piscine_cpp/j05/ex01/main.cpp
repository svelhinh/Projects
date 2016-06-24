/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:54:05 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 18:24:26 by svelhinh         ###   ########.fr       */
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
	yo->signForm(form);
	std::cout << "\033[33m" << *form << std::endl;

	std::cout << "\033[36m" << *yo << std::endl;
	for (int i = 0; i < 148; i++)
		yo->inc();
	std::cout << "\033[36m" << *yo << std::endl;

	std::cout << "\033[33m" << *form << std::endl;
	std::cout << "\033[36m";
	yo->signForm(form);
	std::cout << "\033[33m" << *form << std::endl;

	delete yo;
	return 0;
}
