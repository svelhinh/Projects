/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:25:19 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/07 18:25:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim
{
public:
    Victim(std::string name_);
    Victim(Victim const & src);
    ~Victim();

    virtual void	getPolymorphed() const;

    std::string getName() const;

    Victim &    operator=( Victim const & rhs );

protected:
    Victim();
    std::string name;
};

std::ostream &	operator<<( std::ostream & o, Victim const & vic);

#endif
