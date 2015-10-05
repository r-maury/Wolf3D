/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 14:01:16 by rmaury            #+#    #+#             */
/*   Updated: 2015/10/05 00:46:20 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define BUFF_SIZE 20

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
	int				width;
	int				heigh;
}					t_mlx;

typedef struct		s_player
{
	int		**map;
	int		map_x;
	int		map_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}					t_player;

int		**map_select(int n, void *mlx, void *win);
void	draw_map(t_mlx *m, t_player *p);

#endif
