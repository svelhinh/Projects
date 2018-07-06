/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:25:19 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:20:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon(std::string name_);
    Peon(Peon const & src);
    ~Peon();

    void	getPolymorphed() const;

    Peon &	operator=( Peon const & rhs );

private:
    Peon();
};

#endif
