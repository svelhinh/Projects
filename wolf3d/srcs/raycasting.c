/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:10:37 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/26 12:21:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_var(t_ray *r)
{
	// x et y position de depart
	r->posX = 2;
	r->posY = 2; 

	///initialisation du verteur directeur
	r->dirX = -1;
	r->dirY = 0;

	// Raycaster la deuxieme version du plan camera
	r->planeX = 0;
	r->planeY = 0.66;
}

static void	calculs(t_ray *r)
{
	r->x = 0;
	while (r->x < SWIDTH)
	{
		///calcul de la position et de l'orientation du rayon
		r->cameraX = 2 * r->x / (double)SWIDTH - 1;	///Coordonnees x dans l'espace de la camera
		r->rayPosX = r->posX;						///  Coordonnees x du rayon dans l'espace
		r->rayPosY = r->posY;						/// Coordonnees y du rayon dans l'espace
		r->rayDirX = r->dirX + r->planeX * r->cameraX;
		r->rayDirY = r->dirY + r->planeY * r->cameraX;
	
		///Dans quelle case de la carte, nous nous situons au debut
		r->mapX = (int)r->rayPosX;
		r->mapY = (int)r->rayPosY;

		///Longueur des rayons de la position actuelle au prochain x ou y
		double distMurX; ///Distance entre le joueur et 1e prochain mur vertical
		double distMurY; ///Distance entre le joueur et 1e prochain mur horizontal

		///Longueur des rayons de la position  du x ou y actuel au prochain x ou y
		dist2MurX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX)); ///Distance entre deux murs verticaux
		dist2MurY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY)); ///Distance entre deux murs horizontaux
		double longueurMur;}
		r->x++;
	}
}

void		raycasting(t_env e)
{
	t_ray r;

	init_var(&r);
}
