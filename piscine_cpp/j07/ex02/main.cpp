/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:20:49 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/12 18:20:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int> tab(15);
	Array<int> tab2(15);

	for(size_t i = 0; i < tab.size(); i++)
	{
		tab[i] = i;
		tab2[i] = i + 1;
		std::cout << tab[i] << ", " << tab2[i] << std::endl;
	}

	Array<int> tab3 = tab2;
	for(size_t i = 0; i < tab3.size(); i++)
		std::cout << tab3[i] << std::endl;

	Array<float> * tab4 = new Array<float>(10);
	for(size_t i = 0; i < tab4->size(); i++)
		std::cout << (*tab4)[i] << std::endl;

	try
	{
		std::cout << tab[20] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete tab4;
	return 0;
}
