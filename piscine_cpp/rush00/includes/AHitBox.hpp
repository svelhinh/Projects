/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AHitBox.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 20:37:16 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 20:38:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AHITBOX_HPP
#define AHITBOX_HPP

class AHitBox {
	public:
		AHitBox(AHitBox const & src);
		int getPosX(void) const;
		int getPosY(void) const;
		int getWidth(void) const;
		int getHeight(void) const;

		void setPosX(int x);
		void setPosY(int y);
		void setWidth(int w);
		void setHeight(int h);

		bool collide(AHitBox const & obj) const;

		AHitBox & operator = (AHitBox const & rhs);

	protected:
		AHitBox(void);
		AHitBox(int x, int y, int w, int h);
		virtual ~AHitBox(void);

		int		_x;
		int		_y;
		int		_h;
		int		_w;
};

#endif
