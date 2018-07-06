/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chicken.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:25:19 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:34:08 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHICKEN_HPP
# define CHICKEN_HPP

# include <string>
# include "Victim.hpp"

class Chicken : public Victim
{
public:
    Chicken(std::string name_);
    Chicken(Chicken const & src);
    ~Chicken();

    void	getPolymorphed() const;

    Chicken &	operator=( Chicken const & rhs );

private:
    Chicken();
};

#endif
