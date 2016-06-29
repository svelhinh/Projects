/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:39:28 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 15:13:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T>
class	MutantStack : public std::stack<T>
{
	class iterator
	{
		MutantStack	&rhs;
		int			i;

	public:
		iterator(MutantStack &st, int i);
		iterator(iterator const &rhs);
		~iterator();
		iterator	&operator=(iterator const &rhs);
		iterator	&operator++();
		iterator	&operator--();
		bool		operator==(iterator const &rhs);
		bool		operator!=(iterator const &rhs);
		T			&operator*();
	};
	iterator	begin();
	iterator	end();
};

#endif
