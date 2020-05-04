/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:04:15 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/11 18:56:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void	convertChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	convertFloat(float f)
{
	if (!std::isprint(static_cast<char>(f)))
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::setprecision (3) << f << std::endl;
	std::cout << "double: " << std::setprecision (3) << static_cast<double>(f) << std::endl;
}

int	main(int ac, char **av)
{
	if (std::strlen(av[1]) == 1)
	{
		if (!std::isdigit(av[1][0]))
		{
			convertChar(av[1][0]);
			return 0;
		}
	}

	if (av[1][std::strlen(av[1]) - 1] ==  'f')
	{
		char* pEnd;
		convertFloat(std::strtof(av[1], &pEnd));
	}

	//char	c = av[1];
	// char* pEnd;
	// int		nbI = atoi(av[1]);
	// float	nbF = strtof(av[1], &pEnd);
	// double	nbD = strtod(av[1], &pEnd);

	// std::cout << "char: " << static_cast<char>(nbI) << std::endl;
	// std::cout << "int: " << nbI << std::endl;
	// std::cout << "float: " << static_cast<float>(nbI) << std::endl;
	// std::cout << "double: " << static_cast<double>(nbI) << std::endl;
	//
	// std::cout << "char: " << static_cast<char>(nbF) << std::endl;
	// std::cout << "int: " << static_cast<int>(nbF) << std::endl;
	// std::cout << "float: " << nbF << "f" << std::endl;
	// std::cout << "double: " << static_cast<double>(nbF) << std::endl;
	//std::cout << static_cast<char>(av[1][0]) << std::endl;
	return 0;
}
