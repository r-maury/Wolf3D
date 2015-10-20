/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 14:01:16 by rmaury            #+#    #+#             */
/*   Updated: 2015/10/20 11:47:17 by rmaury           ###   ########.fr       */
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

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"


typedef struct		s_player
{
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
}					t_player;
//ms = move speed
//rs = rotation speed
typedef struct		s_mlx
{
	void			*win;
	void			*mlx;
	int				width;
	int				heigh;
	t_player		*p;
}					t_mlx;

int		**map_select(int n, void *mlx, void *win);
void	draw_map(t_mlx *m);
void	move(t_mlx *m, int keycode);

#endif
