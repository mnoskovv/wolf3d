/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:04:03 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/15 13:24:55 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_window		*new_window(void)
{
	t_window	*new;

	new = (t_window *)ft_memalloc(sizeof(t_window));
	new->image = NULL;
	new->window = NULL;
	new->adress = NULL;
	new->endian = 0;
	new->size_line = 0;
	new->bpp = 0;
	return (new);
}

void			create_window(t_window **window)
{
	(*window)->mlx = mlx_init();
	(*window)->window = mlx_new_window((*window)->mlx,
					SIZE_W, SIZE_H, "wolf 3D");
}

void			border(t_window *wind)
{
	int x;
	int y;

	x = 39;
	y = 39;
	while (x++ < 400)
	{
		y = 39;
		while (y++ < 330)
			wind->adress[y * SIZE_W + x] = 0x9a9a9a;
	}
}

void			hints(t_window *wind)
{
	int x;
	int y;

	x = 35;
	y = 35;
	while (x++ < 404)
	{
		y = 35;
		while (y++ < 334)
			wind->adress[y * SIZE_W + x] = 0x949960;
	}
	border(wind);
	mlx_put_image_to_window(wind->mlx, wind->window, wind->image, 0, 0);
	mlx_string_put(wind->mlx, wind->window, 50, 50, 0xc3e1f4,\
		"controlls:  ^, v, ->, <- или W,A,S,D");
	mlx_string_put(wind->mlx, wind->window, 50, 100, 0xc3e1f4,\
		"rotate: mouse ");
	mlx_string_put(wind->mlx, wind->window, 50, 150, 0xc3e1f4,\
		"boost: r.Shift");
	mlx_string_put(wind->mlx, wind->window, 50, 200, 0xc3e1f4,\
		"switch textures: C");
	mlx_string_put(wind->mlx, wind->window, 50, 250, 0xc3e1f4,\
		"hide hints: H");
	mlx_string_put(wind->mlx, wind->window, 50, 300, 0xc3e1f4,\
		"exit: [esc]");
}
