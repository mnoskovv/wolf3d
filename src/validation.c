/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:52:33 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 20:41:41 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	check_nums(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (ft_atoi(array[i]) >= 0 && ft_atoi(array[i]) <= 16)
			i++;
		else
			exit_errors(5);
	}
	return (1);
}

void		is_valid2(int fst_h[3], char **sptd, t_all *all, char *line)
{
	while (get_next_line(fst_h[2], &line) > 0)
	{
		sptd = ft_strsplit(line, ' ');
		if (len_2d_array(sptd) != fst_h[0])
		{
			free_arr(sptd);
			free(line);
			exit_errors(1);
		}
		if (check_nums(sptd) == 0)
		{
			free_arr(sptd);
			free(line);
			exit_errors(1);
		}
		free_arr(sptd);
		free(line);
		fst_h[1]++;
	}
	all->width = fst_h[0];
	all->height = fst_h[1];
}

int			is_valid(t_all *all)
{
	int		first_height[3];
	char	*line;
	char	**splitted;

	line = NULL;
	first_height[0] = 0;
	first_height[1] = 0;
	first_height[2] = all->fd;
	get_next_line(all->fd, &line);
	if (!line)
		exit_errors(1);
	first_height[1]++;
	if (!line)
		exit_errors(2);
	splitted = ft_strsplit(line, ' ');
	first_height[0] = len_2d_array(splitted);
	if (check_nums(splitted) == 0)
	{
		free_arr(splitted);
		exit_errors(1);
	}
	free(line);
	free_arr(splitted);
	is_valid2(first_height, splitted, all, line);
	return (1);
}
