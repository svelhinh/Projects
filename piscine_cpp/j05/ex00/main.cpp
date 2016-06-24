/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:54:05 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/23 17:01:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat *yo = new Bureaucrat("yo", 149);

	std::cout << *yo << std::endl;
	yo->dec();
	std::cout << *yo << std::endl;
	yo->dec();
	std::cout << *yo << std::endl;
	for (int i = 0; i < 148; i++)
		yo->inc();
	std::cout << *yo << std::endl;
	yo->inc();
	std::cout << *yo << std::endl;
	yo->inc();
	std::cout << *yo << std::endl;

	delete yo;
	return 0;
}
