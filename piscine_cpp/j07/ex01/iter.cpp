/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:44:41 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/12 16:18:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T, typename U>
void	iter( T & array, size_t size, void f(U))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template<typename T>
void	print(T i)
{
	std::cout << i << std::endl;
}

int	main()
{
	int		test[10];

	for (int i = 0; i < 10; i++)
		test[i] = i;
	iter<int[10], int>(test, 10, print<int>);
	std::cout << std::endl;

	double	test2[20];
	double j = 0;
	for (int i = 0; i < 20; i++)
	{
		test2[i] = j;
		j += 0.4;
	}
	iter<double[20], double>(test2, 20, print<double>);
	return 0;
}
