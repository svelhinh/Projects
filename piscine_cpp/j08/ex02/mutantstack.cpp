/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:38:56 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/28 15:12:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return MutantStack<T>::iterator(*this, 0);
}

typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return MutantStack<T>::iterator(*this, this->size());
}
