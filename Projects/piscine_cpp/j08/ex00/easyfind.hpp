/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:48:23 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/13 12:00:26 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyfind_tpp
#define easyfind_tpp

#include <algorithm>
#include <iostream>

template< typename T >
void	easyfind(T container, int value)
{
	if (std::find(container.begin(), container.end(), value) == container.end())
		throw std::exception();
}

#endif
