/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 14:01:16 by rmaury            #+#    #+#             */
/*   Updated: 2015/11/30 17:54:35 by rmaury           ###   ########.fr       */
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

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"



//ms = move speed
//rs = rotation speed
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
	double 			deltadist_y;
	double			perpwalldist;
	int		**map;
	int		map_x;
	int		map_y;
	double	ms;
	double	rs;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}					t_mlx;

int		**map_select(int n, void *mlx, void *win);
void	draw_map(t_mlx *m);
void	right_rot(t_mlx *m);
void	left_rot(t_mlx *m);
void	move(t_mlx *m, int keycode);
void	put_pixel_to_image(t_mlx *m, int *color, int x, int y);

#endif
