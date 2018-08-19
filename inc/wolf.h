/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:09:37 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/15 13:30:23 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include <fcntl.h>
# include "mlx.h"

# define TEX_W 64
# define TEX_H 64
# define SIZE_W 900
# define SIZE_H 700
# define RED 0xe7030e
# define BLUE 0x05ece6
# define YELLOW 0xf9ef09
# define GREEN 0x00cc00
# define WHITE 0xffffff
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define BOOST 258
# define C 8
# define H 4
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define SPD 0.05

# define ON_WIND (x > 0 && x < SIZE_W && y > 0 && y < SIZE_H)
# define BST(x)    ((x) == 1 ? SPD * 2 : SPD)

typedef struct		s_windows
{
	void			*mlx;
	void			*image;
	void			*window;
	int				*adress;
	int				endian;
	int				size_line;
	int				bpp;
}					t_window;

typedef struct		s_wolf
{
	double			px;
	double			py;
	double			dx;
	double			dy;
	double			pl_x;
	double			pl_y;
	double			cam_x;
	double			raydx;
	double			raydy;
	int				mapx;
	int				mapy;
	double			sdx;
	double			sdy;
	double			ddx;
	double			ddy;
	double			wal_dist;
	double			olddx;
	double			oldpl_x;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				heigh_l;
	int				dstart;
	int				dend;
	unsigned int	color;
	int				**map;
	double			wallx;
	int				texx;
	int				texy;
	int				d;
	int				r;
	int				g;
	int				b;
	double			flx_wll;
	double			fly_wll;
	double			dst_wl;
	double			dst_plr;
	double			c_dst;
	double			wght;
	double			c_fl_x;
	double			c_fl_y;
	int				fl_tx_x;
	int				fl_tx_y;

}					t_wolf;

typedef struct		s_all
{
	int				fd;
	t_window		*wind;
	t_wolf			*w;
	int				width;
	int				height;
	int				up;
	int				down;
	int				left;
	int				right;
	int				curr_x;

	int				text_num;
	void			*im[16];
	char			*bf[16];
	int				e[16];
	int				sl[16];
	int				bp[16];
	int				sw;
	double			boost;
	unsigned int	c;
	unsigned int	h;
}					t_all;

void				exit_errors(int flag);
t_window			*new_window(void);
void				create_window(t_window **window);
int					exit_x(int key, t_all *all);
int					hadle_input_key(int key, t_all *all);
void				init(t_wolf *w);
void				draw(t_all *all);
int					is_valid(t_all *all);
void				read_map(t_all *all);
void				re_init(t_all *all, int x);
void				init(t_wolf *w);
int					pressed(int key, t_all *all);
int					unpressed(int key, t_all *all);
int					move(t_all *all);
void				free_arr(char **splitted);
int					len_2d_array(char **array);
int					mouse(int x, int y, t_all *all);
void				load_textures(t_all *a);
void				put_wall2(t_all *all, int x);
void				put_wall1(t_all *all, int x);
int					draw_textures(t_all *all, int y, int tex);
unsigned int		color(int r, int g, int b);
int					draw_textures(t_all *all, int y, int tex);
void				draw_2(t_all *all, int x);
void				put_wall1(t_all *all, int x);
void				put_wall2(t_all *all, int x);
void				draw_floor_roof(t_all *all, int x, int y);
void				steps();
void				fon();
void				calc_floor_roof(t_all *all);
void				stop_music(int sign);
void				hints(t_window *wind);
void				right_x(t_all *all, int x, int y);
void				redraw(t_all *all);
#endif
