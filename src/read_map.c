/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:57:04 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 18:23:38 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		check_walls(t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->width)
		if (!all->w->map[0][i] || !all->w->map[all->height - 1][i])
			exit_errors(1);
	i = -1;
	while (++i < all->height)
		if (!all->w->map[i][0] || !all->w->map[i][all->width - 1])
			exit_errors(1);
	if (all->height > 100 || all->height < 4)
		exit_errors(6);
	if (all->width > 100 || all->width < 4)
		exit_errors(6);
}

void		read_map(t_all *all)
{
	char	*line;
	char	**spltd;
	int		i;
	int		count;

	i = 0;
	line = NULL;
	all->w->map = (int**)malloc(sizeof(all->w->map) * all->height);
	while (get_next_line(all->fd, &line) > 0)
	{
		spltd = ft_strsplit(line, ' ');
		all->w->map[i] = malloc(sizeof(all->w->map[i]) * all->width);
		count = -1;
		while (++count < all->width)
			all->w->map[i][count] = ft_atoi(spltd[count]);
		free_arr(spltd);
		free(line);
		i++;
	}
	check_walls(all);
}
