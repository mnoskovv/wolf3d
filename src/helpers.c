/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:41:50 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/15 13:28:27 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					exit_x(int key, t_all *all)
{
	(void)all;
	(void)key;
	system("killall -9 afplay");
	exit(0);
	return (0);
}

void				free_arr(char **splitted)
{
	int				i;

	i = 0;
	while (splitted[i])
		ft_strdel(&(splitted[i++]));
	free(splitted);
}

int					len_2d_array(char **array)
{
	int				i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

unsigned int		color(int r, int g, int b)
{
	unsigned int	color;

	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (color);
}

void				stop_music(int sign)
{
	signal(sign, SIG_IGN);
	system("killall -9 afplay");
	exit(0);
}
