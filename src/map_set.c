/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:27:34 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/11 17:58:28 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	map_set_one(t_mlx *m)
{
	m->map_nb = 1;
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
	m->init = 1;
}

static void	map_set_two(t_mlx *m)
{
	m->map_nb = 2;
	m->pos_x = 18.5;
	m->pos_y = 20.5;
	m->dir_x = -1;
	m->dir_y = 0;
	m->plane_x = 0;
	m->plane_y = 0.66;
	m->win_x = 1;
	m->win_y = 1;
	m->spawn_x = m->pos_x;
	m->spawn_y = m->pos_y;
	m->init = 1;
}

static void	map_set_three(t_mlx *m)
{
	m->map_nb = 3;
	m->pos_x = 1.2;
	m->pos_y = 22.2;
	m->dir_x = -1;
	m->dir_y = 0;
	m->plane_x = 0;
	m->plane_y = 0.66;
	m->win_x = 1;
	m->win_y = 1;
	m->spawn_x = m->pos_x;
	m->spawn_y = m->pos_y;
	m->init = 1;
}

static void	map_set_four(t_mlx *m)
{
	m->map_nb = 4;
	m->pos_x = 1.4;
	m->pos_y = 1.7;
	m->dir_x = -1;
	m->dir_y = 0;
	m->plane_x = 0;
	m->plane_y = 0.66;
	m->win_x = 19;
	m->win_y = 21;
	m->spawn_x = m->pos_x;
	m->spawn_y = m->pos_y;
	m->init = 1;
}

void		switch_map(t_mlx *m, int key)
{
	if (m->init == 1 && key - 82 != m->map_nb && key - 17 != m->map_nb)
		free(m->map);
	m->init = 0;
	if ((key == 83 || key == 18) && m->map_nb != 1)
		map_set_one(m);
	else if ((key == 84 || key == 19) && m->map_nb != 2)
		map_set_two(m);
	else if ((key == 85 || key == 20) && m->map_nb != 3)
		map_set_three(m);
	else if ((key == 86 || key == 21) && m->map_nb != 4)
		map_set_four(m);
	if (m->init == 1)
	{
		m->map = map_select(m);
		draw_map(m);
	}
}
