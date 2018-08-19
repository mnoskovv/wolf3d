/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:03:45 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 19:48:20 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check(char *argv)
{
	if (ft_strstr(argv, "/dev/"))
		exit_errors(3);
	if (!ft_strstr(argv, "maps/"))
		exit_errors(3);
}

void	next_step(t_all *a, char *path)
{
	close(a->fd);
	a->fd = open(path, O_RDONLY);
	read_map(a);
	init(a->w);
	a->sw = 1;
	load_textures(a);
	draw(a);
	fon();
	a->up = 0;
	a->down = 0;
	a->left = 0;
	a->right = 0;
	a->curr_x = 0;
	mlx_put_image_to_window(a->wind->mlx, a->wind->window,
		a->wind->image, 0, 0);
	mlx_do_key_autorepeatoff(a->wind->mlx);
	signal(SIGINT, stop_music);
	mlx_hook(a->wind->window, 6, 0, mouse, a);
	mlx_hook(a->wind->window, 2, 0, pressed, a);
	mlx_hook(a->wind->window, 3, 0, unpressed, a);
	mlx_hook(a->wind->window, 17, 1L << 17, exit_x, a);
	mlx_loop_hook(a->wind->mlx, move, a);
	mlx_loop(a->wind->mlx);
}

int		main(int argc, char **argv)
{
	t_window	*wind;
	t_wolf		*w;
	t_all		*all;

	if (argc != 2)
		exit_errors(3);
	if (!(w = malloc(sizeof(t_wolf))) ||
		!(all = malloc(sizeof(t_all))))
		return (0);
	if ((all->fd = open(argv[1], O_RDONLY)) == -1)
		exit_errors(2);
	wind = NULL;
	wind = new_window();
	create_window(&wind);
	wind->image = mlx_new_image(wind->mlx, SIZE_W, SIZE_H);
	wind->adress = (int *)mlx_get_data_addr(wind->image, &wind->endian,
		&wind->size_line, &wind->bpp);
	all->w = w;
	check(argv[1]);
	all->wind = wind;
	if (!(is_valid(all)))
		exit_errors(1);
	next_step(all, argv[1]);
	return (0);
}
