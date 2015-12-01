/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 17:31:02 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/01 10:49:25 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	right_rot(t_mlx *m)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = m->dir_x;
	m->dir_x = m->dir_x * cos(-m->rs) - m->dir_y * sin(-m->rs);
	m->dir_y = olddir_x * sin(-m->rs) + m->dir_y * cos(-m->rs);
	oldplane_x = m->plane_x;
	m->plane_x = m->plane_x * cos(-m->rs) - m->plane_y * sin(-m->rs);
	m->plane_y = oldplane_x * sin(-m->rs) + m->plane_y * cos(-m->rs);
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}

void	left_rot(t_mlx *m)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = m->dir_x;
	m->dir_x = m->dir_x * cos(m->rs) - m->dir_y * sin(m->rs);
	m->dir_y = olddir_x * sin(m->rs) + m->dir_y * cos(m->rs);
	oldplane_x = m->plane_x;
	m->plane_x = m->plane_x * cos(m->rs) - m->plane_y * sin(m->rs);
	m->plane_y = oldplane_x * sin(m->rs) + m->plane_y * cos(m->rs);
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}
