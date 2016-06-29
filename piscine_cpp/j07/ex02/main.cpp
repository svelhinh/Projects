/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:59:34 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 12:19:18 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int> tab(15);

	for(int i = 0; i < tab.size(); i++)
	{
		tab[i] = i;
		std::cout << tab[i] << " ";
	}
	return (0);
}