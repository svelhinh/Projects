/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 13:08:54 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 13:31:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iostream>

template<typename T>
void	easyfind(T dest, int src)
{
	typename T::iterator it = find(dest.begin(), dest.end(), src);
	if (it == dest.end())
		throw std::exception();
}

#endif
