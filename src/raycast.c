/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:52:48 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 19:23:12 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_x_y(t_all *all)
{
	while (all->w->hit == 0)
	{
		if (all->w->sdx < all->w->sdy)
		{
			all->w->sdx += all->w->ddx;
			all->w->mapx += all->w->stepx;
			all->w->side = 0;
		}
		else
		{
			all->w->sdy += all->w->ddy;
			all->w->mapy += all->w->stepy;
			all->w->side = 1;
		}
		if (all->w->map[all->w->mapx][all->w->mapy] > 0)
		{
			all->w->hit = 1;
		}
	}
}

void	calc_step(t_all *all)
{
	if (all->w->raydx < 0)
	{
		all->w->stepx = -1;
		all->w->sdx = (all->w->px - all->w->mapx) * all->w->ddx;
	}
	else
	{
		all->w->stepx = 1;
		all->w->sdx = (all->w->mapx + 1.0 - all->w->px) * all->w->ddx;
	}
	if (all->w->raydy < 0)
	{
		all->w->stepy = -1;
		all->w->sdy = (all->w->py - all->w->mapy) * all->w->ddy;
	}
	else
	{
		all->w->stepy = 1;
		all->w->sdy = (all->w->mapy + 1.0 - all->w->py) * all->w->ddy;
	}
}

void	build_cycle(t_all *all, int y, int x)
{
	while (y++ < SIZE_H)
	{
		all->w->c_dst = SIZE_H / (2.0 * y - SIZE_H);
		all->w->wght = (all->w->c_dst - all->w->dst_plr)
		/ (all->w->dst_wl - all->w->dst_plr);
		all->w->c_fl_x = all->w->wght * all->w->flx_wll
		+ (1.0 - all->w->wght) * all->w->px;
		all->w->c_fl_y = all->w->wght * all->w->fly_wll
		+ (1.0 - all->w->wght) * all->w->py;
		all->w->fl_tx_x = (int)(all->w->c_fl_x * TEX_W) % TEX_W;
		all->w->fl_tx_y = (int)(all->w->c_fl_y * TEX_H) % TEX_H;
		draw_floor_roof(all, x, y);
	}
}

void	draw(t_all *all)
{
	int x;

	x = 0;
	ft_memset(all->wind->adress, 0, SIZE_W * SIZE_H * 4);
	(all->h % 2 == 0) ? hints(all->wind) : 0;
	while (x++ < SIZE_W)
	{
		re_init(all, x);
		calc_step(all);
		move_x_y(all);
		if (all->w->side == 0)
			all->w->wal_dist = (all->w->mapx - all->w->px +
			(1 - all->w->stepx) / 2) / all->w->raydx;
		else
			all->w->wal_dist = (all->w->mapy - all->w->py +
			(1 - all->w->stepy) / 2) / all->w->raydy;
		all->w->heigh_l = (int)(SIZE_H / all->w->wal_dist);
		all->w->dstart = -all->w->heigh_l / 2 + SIZE_H / 2;
		if (all->w->dstart < 0)
			all->w->dstart = 0;
		all->w->dend = all->w->heigh_l / 2 + SIZE_H / 2;
		if (all->w->dend >= SIZE_H)
			all->w->dend = SIZE_H - 1;
		draw_2(all, x);
	}
}

void	draw_2(t_all *all, int x)
{
	int y;

	if (all->w->side == 0)
		all->w->wallx = all->w->py + all->w->wal_dist * all->w->raydy;
	else
		all->w->wallx = all->w->px + all->w->wal_dist * all->w->raydx;
	all->w->wallx -= floor((all->w->wallx));
	all->w->texx = (int)(all->w->wallx * (double)TEX_W);
	if (all->w->side == 0 && all->w->raydx > 0)
		all->w->texx = TEX_W - all->w->texx - 1;
	if (all->w->side == 1 && all->w->raydy < 0)
		all->w->texx = TEX_W - all->w->texx - 1;
	if (all->sw % 2 == 0)
		put_wall2(all, x);
	else
		put_wall1(all, x);
	calc_floor_roof(all);
	y = all->w->dend + 1;
	build_cycle(all, y, x);
}
