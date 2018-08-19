/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:04:14 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/15 13:28:24 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	exit_errors(int flag)
{
	if (flag == 1)
		ft_putendl("invalid map!");
	if (flag == 2)
		ft_putendl("cannot open file!");
	if (flag == 3)
		ft_putendl("Usage : ./wolf3d maps/[map name]");
	if (flag == 4)
		ft_putendl("wrong map, because you put a wall on start pos :(");
	if (flag == 5)
		ft_putendl("you can set numbers between 0 and 16 :D");
	if (flag == 6)
		ft_putendl("wrong map size :(");
	if (flag == 8)
		ft_putendl("no texure found:(");
	exit(0);
}
