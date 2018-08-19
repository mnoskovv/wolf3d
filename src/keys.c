/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:03:32 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 18:06:30 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mouse(int x, int y, t_all *all)
{
	right_x(all, x, y);
	if (x < all->curr_x || x < 0)
	{
		all->w->olddx = all->w->dx;
		all->w->dx = all->w->dx * cos(SPD * 2) - all->w->dy * sin(SPD * 2);
		all->w->dy = all->w->olddx * sin(SPD * 2)
		+ all->w->dy * cos(SPD * 2);
		all->w->oldpl_x = all->w->pl_x;
		all->w->pl_x = all->w->pl_x * cos(SPD * 2)
		- all->w->pl_y * sin(SPD * 2);
		all->w->pl_y = all->w->oldpl_x * sin(SPD * 2)
		+ all->w->pl_y * cos(SPD * 2);
	}
	all->curr_x = x;
	redraw(all);
	return (0);
}

void	turn(t_all *all)
{
	if (all->right == 1)
	{
		all->w->olddx = all->w->dx;
		all->w->dx = all->w->dx * cos(-SPD) - all->w->dy * sin(-SPD);
		all->w->dy = all->w->olddx * sin(-SPD) + all->w->dy * cos(-SPD);
		all->w->oldpl_x = all->w->pl_x;
		all->w->pl_x = all->w->pl_x * cos(-SPD) - all->w->pl_y * sin(-SPD);
		all->w->pl_y = all->w->oldpl_x * sin(-SPD) + all->w->pl_y * cos(-SPD);
	}
	if (all->left == 1)
	{
		all->w->olddx = all->w->dx;
		all->w->dx = all->w->dx * cos(SPD) - all->w->dy * sin(SPD);
		all->w->dy = all->w->olddx * sin(SPD) + all->w->dy * cos(SPD);
		all->w->oldpl_x = all->w->pl_x;
		all->w->pl_x = all->w->pl_x * cos(SPD) - all->w->pl_y * sin(SPD);
		all->w->pl_y = all->w->oldpl_x * sin(SPD) + all->w->pl_y * cos(SPD);
	}
}

int		pressed(int key, t_all *all)
{
	if (key == UP || key == W)
		all->up = 1;
	if (key == DOWN || key == S)
		all->down = 1;
	if (key == LEFT || key == A)
		all->left = 1;
	if (key == RIGHT || key == D)
		all->right = 1;
	if (key == ESC)
		exit_x(key, all);
	if (key == BOOST)
		all->boost = 1;
	if (key == C)
		all->sw += 1;
	if (key == H)
		all->h += 1;
	return (0);
}

int		unpressed(int key, t_all *all)
{
	if (key == UP || key == W)
		all->up = 0;
	if (key == DOWN || key == S)
		all->down = 0;
	if (key == LEFT || key == A)
		all->left = 0;
	if (key == RIGHT || key == D)
		all->right = 0;
	if (key == BOOST)
		all->boost = 0;
	return (0);
}

int		move(t_all *all)
{
	if (all->up == 1 && (all->c += 1))
	{
		if (all->w->map[(int)(all->w->px + all->w->dx
			* 0.3)][(int)(all->w->py)] == 0)
			all->w->px += all->w->dx * BST(all->boost);
		if (all->w->map[(int)(all->w->px)][(int)(all->w->py
			+ all->w->dy * 0.3)] == 0)
			all->w->py += all->w->dy * BST(all->boost);
		if (all->c == 1 || all->c % 24 == 0)
			steps();
		if (all->boost && all->c % 15 == 0)
			steps();
	}
	if (all->down == 1)
	{
		if (all->w->map[(int)(all->w->px - all->w->dx
			* 0.3)][(int)(all->w->py)] == 0)
			all->w->px -= all->w->dx * SPD;
		if (all->w->map[(int)(all->w->px)][(int)(all->w->py
			- all->w->dy * 0.3)] == 0)
			all->w->py -= all->w->dy * SPD;
	}
	turn(all);
	redraw(all);
	return (0);
}
