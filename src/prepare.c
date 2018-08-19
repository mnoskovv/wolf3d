/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:42:34 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 19:23:11 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		re_init(t_all *all, int x)
{
	all->w->cam_x = 2 * x / (double)SIZE_W - 1;
	all->w->raydx = all->w->dx + all->w->pl_x * all->w->cam_x;
	all->w->raydy = all->w->dy + all->w->pl_y * all->w->cam_x;
	all->w->mapx = (int)all->w->px;
	all->w->mapy = (int)all->w->py;
	all->w->ddx = fabs(1 / all->w->raydx);
	all->w->ddy = fabs(1 / all->w->raydy);
	all->w->hit = 0;
}

void		init(t_wolf *w)
{
	w->px = 1.5;
	w->py = 1.5;
	w->dx = -1;
	w->dy = 0;
	w->pl_x = 0;
	w->pl_y = 0.66;
	if (w->map[(int)w->px][(int)w->py] != 0)
		exit_errors(4);
}

void		redraw(t_all *all)
{
	draw(all);
	mlx_put_image_to_window(all->wind->mlx, all->wind->window,
		all->wind->image, 0, 0);
	if (all->h % 2 == 0)
		hints(all->wind);
}

void		right_x(t_all *all, int x, int y)
{
	(void)y;
	if (x > all->curr_x)
	{
		all->w->olddx = all->w->dx;
		all->w->dx = all->w->dx * cos(-SPD * 2) - all->w->dy * sin(-SPD * 2);
		all->w->dy = all->w->olddx * sin(-SPD * 2) + all->w->dy * cos(-SPD * 2);
		all->w->oldpl_x = all->w->pl_x;
		all->w->pl_x = all->w->pl_x * cos(-SPD * 2)
		- all->w->pl_y * sin(-SPD * 2);
		all->w->pl_y = all->w->oldpl_x * sin(-SPD * 2)
		+ all->w->pl_y * cos(-SPD * 2);
	}
}
