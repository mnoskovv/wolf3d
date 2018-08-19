/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_floor_roof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:47:49 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 18:57:44 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		put_wall1(t_all *all, int x)
{
	int		i;

	i = all->w->dstart;
	if (all->w->map[all->w->mapx][all->w->mapy] != 0)
		all->text_num = all->w->map[all->w->mapx][all->w->mapy] - 1;
	if (all->w->map[all->w->mapx][all->w->mapy] > 15)
		all->text_num = 0;
	while (i++ < all->w->dend)
	{
		all->w->color = draw_textures(all, i, all->text_num);
		if (all->w->side == 1)
			all->w->color = (all->w->color >> 1) & 8355711;
		if (x >= 0 && i >= 0 && x < SIZE_W && i < SIZE_H)
			all->wind->adress[i * SIZE_W + x] = all->w->color;
	}
}

void		put_wall2(t_all *all, int x)
{
	int		i;

	i = all->w->dstart;
	while (i++ < all->w->dend)
	{
		if (all->w->side == 0)
		{
			if (all->w->stepx < 0)
				all->w->color = draw_textures(all, i, 0);
			else
				all->w->color = draw_textures(all, i, 5);
		}
		else if (all->w->side == 1)
		{
			if (all->w->stepy < 0)
				all->w->color = draw_textures(all, i, 3);
			else
				all->w->color = draw_textures(all, i, 4);
			if (all->w->side == 1)
				all->w->color = (all->w->color >> 1) & 8355711;
		}
		if (x >= 0 && i >= 0 && x < SIZE_W && i < SIZE_H)
			all->wind->adress[i * SIZE_W + x] = all->w->color;
	}
}

void		draw_floor_roof(t_all *all, int x, int y)
{
	all->w->r = all->bf[4][all->sl[4] * all->w->fl_tx_y +
						all->w->fl_tx_x * 4 + 2];
	all->w->g = all->bf[4][all->sl[4] * all->w->fl_tx_y +
						all->w->fl_tx_x * 4 + 1];
	all->w->b = all->bf[4][all->sl[4] * all->w->fl_tx_y +\
						all->w->fl_tx_x * 4];
	all->w->color = color(all->w->r, all->w->g, all->w->b);
	all->w->color = (all->w->color >> 1) & 8355711;
	if (x >= 0 && y >= 0 && x < SIZE_W && y < SIZE_H)
		all->wind->adress[y * SIZE_W + x] = all->w->color;
	all->w->r = all->bf[13][all->sl[13] * all->w->fl_tx_y +
						all->w->fl_tx_x * 4 + 2];
	all->w->g = all->bf[13][all->sl[13] * all->w->fl_tx_y +
						all->w->fl_tx_x * 4 + 1];
	all->w->b = all->bf[13][all->sl[13] * all->w->fl_tx_y +\
						all->w->fl_tx_x * 4];
	all->w->color = color(all->w->r, all->w->g, all->w->b);
	all->w->color = (all->w->color >> 1) & 8355711;
	if (x >= 0 && SIZE_H - y >= 0 && x < SIZE_W && SIZE_H - y < SIZE_H)
		all->wind->adress[(SIZE_H - y) * SIZE_W + x] = all->w->color;
}

void		calc_floor_roof(t_all *all)
{
	if (all->w->side == 0 && all->w->raydx > 0)
	{
		all->w->flx_wll = all->w->mapx;
		all->w->fly_wll = all->w->mapy + all->w->wallx;
	}
	else if (all->w->side == 0 && all->w->raydx < 0)
	{
		all->w->flx_wll = all->w->mapx + 1.0;
		all->w->fly_wll = all->w->mapy + all->w->wallx;
	}
	else if (all->w->side == 1 && all->w->raydy > 0)
	{
		all->w->flx_wll = all->w->mapx + all->w->wallx;
		all->w->fly_wll = all->w->mapy;
	}
	else
	{
		all->w->flx_wll = all->w->mapx + all->w->wallx;
		all->w->fly_wll = all->w->mapy + 1.0;
	}
	all->w->dst_wl = all->w->wal_dist;
	all->w->dst_plr = 0.0;
	if (all->w->dend < 0)
		all->w->dend = SIZE_H;
}
