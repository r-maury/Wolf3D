/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:27:34 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/18 18:15:08 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	map_set_one(t_mlx *m)
{
	m->pos_x = 1.5;
	m->pos_y = 1.5;
	m->dir_x = 0.416147;
	m->dir_y = 0.909297;
	m->plane_x = 0.600136;
	m->plane_y = -0.274657;
	m->win_x = 22;
	m->win_y = 22;
	m->spawn_x = m->pos_x;
	m->spawn_y = m->pos_y;
}

static void	map_set_two(t_mlx *m)
{
	m->ms = 0.5;
	m->map_nb = 2;
	m->pos_x = 18.5;
	m->pos_y = 20.5;
	m->dir_x = -0.825336;
	m->dir_y = -0.564642;
	m->plane_x = -0.372664;
	m->plane_y = 0.544722;
	m->win_x = 1;
	m->win_y = 1;
	m->spawn_x = m->pos_x;
	m->spawn_y = m->pos_y;
	m->init = 0;
}

static void	map_set_three(t_mlx *m)
{
	m->ms = 0.5;
	m->map_nb = 3;
	m->pos_x = 2.5;
	m->pos_y = 22.2;
	m->dir_x = 0.904072;
	m->dir_y = -0.427380;
	m->plane_x = -0.282071;
	m->plane_y = -0.596688;
	m->win_x = 1;
	m->win_y = 1;
	m->spawn_x = m->pos_x;
	m->spawn_y = m->pos_y;
	m->init = 0;
}

static void	map_set_four(t_mlx *m)
{
	m->ms = 0.5;
	m->map_nb = 4;
	m->pos_x = 1.4;
	m->pos_y = 1.7;
	m->dir_x = 0.112153;
	m->dir_y = 0.993691;
	m->plane_x = 0.655836;
	m->plane_y = -0.074021;
	m->win_x = 19;
	m->win_y = 21;
	m->spawn_x = m->pos_x;
	m->spawn_y = m->pos_y;
	m->init = 0;
}

void		switch_map(t_mlx *m, int key)
{
	if (key == 83 && m->init == -1)
		map_set_one(m);
	if (m->init != -1)
	{
		if (key == 84 && m->map_nb == 1 && is_win(m) == 1)
			map_set_two(m);
		else if (key == 85 && m->map_nb == 2 && is_win(m) == 1)
			map_set_three(m);
		else if (key == 86 && m->map_nb == 3 && is_win(m) == 1)
			map_set_four(m);
	}
	if (m->init == 0)
		free(m->map);
}
