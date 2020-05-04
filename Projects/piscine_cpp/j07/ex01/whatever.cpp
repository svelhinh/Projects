/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:57:52 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 11:57:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename A , typename L , typename F >
void	iter( A * array, L len, F func )
{
	for(int i = 0; i < len; i++)
		func(array[i]);
}

void	print_int(int i)
{
	std::cout << i << ", ";
}

void	print_double(double i)
{
	std::cout << i << ", ";
}

int	main()
{
	// int

	int		test[10];
	int		i = 0;
	while (i < 10)
	{
		test[i] = i;
		i++;
	}
	iter(test, 10, print_int);
	std::cout << std::endl;


	// double

	double	test2[10];
	i = 0;
	double	j = 0;
	while (i < 10)
	{
		test2[i] = j;
		i++;
		j += 0.4;
	}
	iter(test2, 10, print_double);
	return (0);
}
