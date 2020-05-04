/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:09:39 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/04 15:54:49 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
public:
    Brain(int const intelligenceLevel_, float const weight_);
    ~Brain();
	std::string identify() const;

private:
    int const	qi;
	float const	weight;
};


#endif
