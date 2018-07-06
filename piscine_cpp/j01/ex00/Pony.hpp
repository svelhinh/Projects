/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:01:22 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 19:47:59 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class	Pony
{
public:
	Pony(std::string const name_, int const color_, float const height_);
	~Pony();
	std::string	const	name;
	int const			color;
	float const			height;
};
void	ponyOnTheHeap(std::string const name_, int const color_, float const height_);
void	ponyOnTheStack(std::string const name_, int const color_, float const height_);

#endif
