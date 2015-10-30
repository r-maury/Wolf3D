/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 17:31:02 by rmaury            #+#    #+#             */
/*   Updated: 2015/10/30 17:54:50 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	right_rot(t_mlx *m)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = m->p->dir_x;
	m->p->dir_x = m->p->dir_x * cos(-m->p->rs) - m->p->dir_y * sin(-m->p->rs);
	m->p->dir_y = olddir_x * sin(-m->p->rs) + m->p->dir_y * cos(-m->p->rs);
	oldplane_x = m->p->plane_x;
	m->p->plane_x = m->p->plane_x * cos(-m->p->rs) - m->p->plane_y * sin(-m->p->rs);
	m->p->plane_y = oldplane_x * sin(-m->p->rs) + m->p->plane_y * cos(-m->p->rs);
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}

void	left_rot(t_mlx *m)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = m->p->dir_x;
	m->p->dir_x = m->p->dir_x * cos(m->p->rs) - m->p->dir_y * sin(m->p->rs);
	m->p->dir_y = olddir_x * sin(m->p->rs) + m->p->dir_y * cos(m->p->rs);
	oldplane_x = m->p->plane_x;
	m->p->plane_x = m->p->plane_x * cos(m->p->rs) - m->p->plane_y * sin(m->p->rs);
	m->p->plane_y = oldplane_x * sin(m->p->rs) + m->p->plane_y * cos(m->p->rs);
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}