/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:25:19 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:29:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOAT_HPP
# define GOAT_HPP

# include <string>
# include "Victim.hpp"

class Goat : public Victim
{
public:
    Goat(std::string name_);
    Goat(Goat const & src);
    ~Goat();

    void	getPolymorphed() const;

    Goat &	operator=( Goat const & rhs );

private:
    Goat();
};

#endif
