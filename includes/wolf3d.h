/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 14:01:16 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/09 16:07:18 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define BUFF_SIZE 20
# define U_ARROW 126
# define D_ARROW 125
# define L_ARROW 123
# define R_ARROW 124
# define W 13
# define S 1
# define A 0
# define D 2
# define E 14
# define Q 12
# define KEYPRESSMASK (1L<<0)
# define KEYPRESS 2
# define WELCOME "Welcome To Wolf3D"
# define PRESS "Please press a key between 1 & 4"
# define ESC "Or escape to quit"

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

typedef struct		s_mlx
{
	void			*win;
	void			*mlx;
	void			*img;
	int				pix;
	int				sizeline;
	int				bpp;
	int				endian;
	char			*data;
	int				width;
	int				heigh;
	double			fps;
	double			cam_x;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				color;
	double			rayp_x;
	double			rayp_y;
	double			rayd_x;
	double			rayd_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				**map;
	int				map_x;
	int				map_y;
	double			ms;
	double			rs;
	double			pos_x;
	double			pos_y;
	double			spawn_x;
	double			spawn_y;
	double			win_x;
	double			win_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				init;
	int				map_nb;
}					t_mlx;

void				init_wolf(t_mlx *mlx);
void				switch_map(t_mlx *mlx, int keycode);
int					key_hook2(int keycode, t_mlx *mlx);
int					key_hook(int keycode, t_mlx *mlx);
int					expose_hook(t_mlx *mlx);
void				map_error();
int					**fill_map_array(char *m, int line, int **map);
int					**map_get(int fd);
int					**map_select(t_mlx *m);
void				set_heigh(t_mlx *m);
void				wall_dist(t_mlx *m);
void				ft_rays(t_mlx *m);
void				optical_corrector(t_mlx *m);
void				check_pos(t_mlx *m);
void				put_pixel_to_image(t_mlx *m, int *color, int x, int y);
void				draw_map(t_mlx *m);
void				right_rot(t_mlx *m);
void				left_rot(t_mlx *m);
void				move(t_mlx *m, int keycode);

#endif
