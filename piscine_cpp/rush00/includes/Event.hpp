/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:43 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 20:38:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HPP
#define EVENT_HPP

enum e_keys {
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_SHOOT,
	K_ESC,
	K_NKEYS
};

class Event {
	public:
		Event(void);
		Event(Event const & src);
		virtual ~Event(void);

		Event & operator = (Event const & rhs);

		void update(void);

		bool isPressed(int key) const;

	private:
		bool _keys[K_NKEYS];
};

#endif
