/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:36:08 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 18:45:35 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_tex(t_all *all)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (all->im[i] == NULL)
			exit_errors(8);
		i++;
	}
}

void	load_textures_data(t_all *a)
{
	a->bf[0] = mlx_get_data_addr(a->im[0], &a->bp[0], &a->sl[0], &a->e[0]);
	a->bf[1] = mlx_get_data_addr(a->im[1], &a->bp[1], &a->sl[1], &a->e[1]);
	a->bf[2] = mlx_get_data_addr(a->im[2], &a->bp[2], &a->sl[2], &a->e[2]);
	a->bf[3] = mlx_get_data_addr(a->im[3], &a->bp[3], &a->sl[3], &a->e[3]);
	a->bf[4] = mlx_get_data_addr(a->im[4], &a->bp[4], &a->sl[4], &a->e[4]);
	a->bf[5] = mlx_get_data_addr(a->im[5], &a->bp[5], &a->sl[5], &a->e[5]);
	a->bf[6] = mlx_get_data_addr(a->im[6], &a->bp[6], &a->sl[6], &a->e[6]);
	a->bf[7] = mlx_get_data_addr(a->im[7], &a->bp[7], &a->sl[7], &a->e[7]);
	a->bf[8] = mlx_get_data_addr(a->im[8], &a->bp[8], &a->sl[8], &a->e[8]);
	a->bf[9] = mlx_get_data_addr(a->im[9], &a->bp[9], &a->sl[9], &a->e[9]);
	a->bf[10] = mlx_get_data_addr(a->im[10], &a->bp[10], &a->sl[10], &a->e[10]);
	a->bf[11] = mlx_get_data_addr(a->im[11], &a->bp[11], &a->sl[11], &a->e[11]);
	a->bf[12] = mlx_get_data_addr(a->im[12], &a->bp[12], &a->sl[12], &a->e[12]);
	a->bf[13] = mlx_get_data_addr(a->im[13], &a->bp[13], &a->sl[13], &a->e[13]);
	a->bf[14] = mlx_get_data_addr(a->im[14], &a->bp[14], &a->sl[14], &a->e[14]);
}

void	load_textures(t_all *a)
{
	int w;
	int h;

	w = 64;
	h = 64;
	a->im[0] = mlx_xpm_file_to_image(a->wind->mlx, "tex/bluestone.xpm", &w, &h);
	a->im[1] = mlx_xpm_file_to_image(a->wind->mlx, "tex/eagle.xpm", &w, &h);
	a->im[2] = mlx_xpm_file_to_image(a->wind->mlx, "tex/e_block.xpm", &w, &h);
	a->im[3] = mlx_xpm_file_to_image(a->wind->mlx, "tex/flag_1.xpm", &w, &h);
	a->im[4] = mlx_xpm_file_to_image(a->wind->mlx, "tex/floor_1.xpm", &w, &h);
	a->im[5] = mlx_xpm_file_to_image(a->wind->mlx, "tex/gate.xpm", &w, &h);
	a->im[6] = mlx_xpm_file_to_image(a->wind->mlx, "tex/gate2.xpm", &w, &h);
	a->im[7] = mlx_xpm_file_to_image(a->wind->mlx, "tex/gitler.xpm", &w, &h);
	a->im[8] = mlx_xpm_file_to_image(a->wind->mlx, "tex/greystone.xpm", &w, &h);
	a->im[9] = mlx_xpm_file_to_image(a->wind->mlx, "tex/kamin.xpm", &w, &h);
	a->im[10] = mlx_xpm_file_to_image(a->wind->mlx, "tex/me_wall.xpm", &w, &h);
	a->im[11] = mlx_xpm_file_to_image(a->wind->mlx, "tex/mossy.xpm", &w, &h);
	a->im[12] = mlx_xpm_file_to_image(a->wind->mlx, "tex/redbrick.xpm", &w, &h);
	a->im[13] = mlx_xpm_file_to_image(a->wind->mlx, "tex/roof.xpm", &w, &h);
	a->im[14] = mlx_xpm_file_to_image(a->wind->mlx, "tex/wood.xpm", &w, &h);
	check_tex(a);
	load_textures_data(a);
}

int		draw_textures(t_all *all, int y, int tex)
{
	all->w->d = y * all->sl[tex] - SIZE_H * 128 + all->w->heigh_l * 128;
	all->w->texy = ((all->w->d * TEX_H) / all->w->heigh_l) / all->sl[tex];
	all->w->r = all->bf[tex][(all->sl[tex] *
		all->w->texy + all->w->texx * 4) + 2];
	all->w->g = all->bf[tex][(all->sl[tex] *
		all->w->texy + all->w->texx * 4) + 1];
	all->w->b = all->bf[tex][all->sl[tex] * all->w->texy + all->w->texx * 4];
	all->w->color = color(all->w->r, all->w->g, all->w->b);
	all->w->color = (all->w->color >> 1) & 8355711;
	return (all->w->color);
}
