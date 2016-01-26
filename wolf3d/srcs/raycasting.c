/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:10:37 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/26 14:48:40 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_var(t_ray *r)
{
	// x et y position de depart
	r->posX = 5;
	r->posY = 4.5;

	///initialisation du verteur directeur
	r->dirX = -1;
	r->dirY = 0;

	// Raycaster la deuxieme version du plan camera
	r->planeX = 0;
	r->planeY = 0.66;

	r->x = 0;
}

static void	calculs(t_ray *r)
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

	///Longueur des rayons de la position  du x ou y actuel au prochain x ou y
	r->dist2MurX = sqrt(1 + pow(r->rayDirY, 2) / pow(r->rayDirX, 2)); ///Distance entre deux murs verticaux
	r->dist2MurY = sqrt(1 + pow(r->rayDirX, 2) / pow(r->rayDirY, 2)); ///Distance entre deux murs horizontaux
}

static void	colisions(t_ray *r)
{
	r->touche = 0;
	///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur vertical le plus proche en fonction de la prochaine etape x
	if (r->rayDirX < 0) /// Si le rayon est oriente vers la gauche
	{
		r->etapeX = -1;
		r->distMurX = (r->rayPosX - r->mapX) * r->dist2MurX; ///  On calcule la distance entre joueur et 1e prochain mur vertical
	}
	else ///Si le rayon est oriente vers la droite
	{
		r->etapeX = 1;
		r->distMurX = (r->mapX + 1.0 - r->rayPosX) * r->dist2MurX; /// On calcule la distance entre joueur et 1e prochain mur vertical
	}

	///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur horizontal le plus proche en fonction de la prochaine etape y
	if (r->rayDirY < 0)
	{
		r->etapeY = -1;///  On recule
		r->distMurY = (r->rayPosY - r->mapY) * r->dist2MurY;///  On calcule la distance entre le joueur et 1e prochain mur horizontal
	}
	else
	{
		r->etapeY = 1;///  On avance
		r->distMurY = (r->mapY + 1.0 - r->rayPosY) * r->dist2MurY;/// On calcule la distance entre joueur et 1e prochain mur horizontal
	}
}

static void	dda(t_ray *r, t_env e)
{
	while (r->touche == 0)
	{
		///Saute au prochain carre de la map soit vers la  direction x, soit vers la direction y en fonction du mur le plus proche
		if (r->distMurX < r->distMurY)
		{
			r->distMurX += r->dist2MurX;
			r->mapX += r->etapeX;
			r->murVertiOuHori = 0; ///Mur vertical
		}
		else
		{
			r->distMurY += r->dist2MurY;
			r->mapY += r->etapeY;
			r->murVertiOuHori = 1; ///Mur vertical
		}

		///Verifier si le rayon a detecte un mur
		if (e.map[r->mapX][r->mapY] > 0)
			r->touche = 1;
	}
}

static void	calcul_lines(t_ray *r)
{
	///Calcul de la distance projetee sur la direction de la camera (La distance oblique donnera un effet fisheye !)
	if (r->murVertiOuHori == 0)
		r->longueurMur = fabs((r->mapX - r->rayPosX + (1 - r->etapeX) / 2) / r->rayDirX);
	else
		r->longueurMur = fabs((r->mapY - r->rayPosY + (1 - r->etapeY) / 2) / r->rayDirY);

	///Calculer la hauteur de la ligne appelee a l'ecran
	r->hauteurMur = abs((int)(SHEIGHT / r->longueurMur));

	///Calculer le plus bas et le plus eleve des pixels a remplir dans la bande actuelle
	r->drawStart = -r->hauteurMur / 2 + SHEIGHT / 2;
	if(r->drawStart < 0)
		r->drawStart = 0;
	r->drawEnd = r->hauteurMur / 2 + SHEIGHT / 2;
	if(r->drawEnd >= SHEIGHT)
		r->drawEnd = SHEIGHT - 1;
}

static void	display(t_ray r, t_env e)
{
	r.color = 0xcccccc;
	if (r.murVertiOuHori == 1)
		r.color = 0x555555;
	r.y = r.drawStart;
	while (r.y < r.drawEnd)
	{
		mlx_pixel_put(e.mlx, e.win, r.x, r.y, r.color);
		r.y++;
	}
}

void		raycasting(t_env e)
{
	t_ray r;

	init_var(&r);
	while (r.x < SWIDTH)
	{
		calculs(&r);
		colisions(&r);
		dda(&r, e);
		calcul_lines(&r);
		display(r, e);
		r.x++;
	}
}
