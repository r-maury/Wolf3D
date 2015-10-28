/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 03:36:02 by rmaury            #+#    #+#             */
/*   Updated: 2015/10/28 18:19:07 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	move(t_mlx *m, int keycode)
{
	double	olddir_x;
	double	oldplane_x;
	m->p->ms = 0.3;
	m->p->rs = 0.1;

	if (keycode == U_ARROW || keycode == W)
	{
		if (m->p->map[(int)(m->p->pos_x + m->p->dir_x * m->p->ms)][(int)m->p->pos_y] == 0)
			m->p->pos_x += m->p->dir_x * m->p->ms;
		if (m->p->map[(int)m->p->pos_x][(int)(m->p->pos_y + m->p->dir_y * m->p->ms)] == 0)
			m->p->pos_y += m->p->dir_y * m->p->ms;
		mlx_clear_window(m->mlx, m->win);
		draw_map(m);
	}
		if (keycode == D_ARROW || keycode == S)
	{
		if (m->p->map[(int)(m->p->pos_x - m->p->dir_x * m->p->ms)][(int)m->p->pos_y] == 0)
			m->p->pos_x -= m->p->dir_x * m->p->ms;
		if (m->p->map[(int)m->p->pos_x][(int)(m->p->pos_y - m->p->dir_y * m->p->ms)] == 0)
			m->p->pos_y -= m->p->dir_y * m->p->ms;
		mlx_clear_window(m->mlx, m->win);
		draw_map(m);
	}
	if (keycode == R_ARROW)
	{
		olddir_x = m->p->dir_x;
		m->p->dir_x = m->p->dir_x * cos(-m->p->rs) - m->p->dir_y * sin(-m->p->rs);
		m->p->dir_y = olddir_x * sin(-m->p->rs) + m->p->dir_y * cos(-m->p->rs);
		oldplane_x = m->p->plane_x;
		m->p->plane_x = m->p->plane_x * cos(-m->p->rs) - m->p->plane_y * sin(-m->p->rs);
		m->p->plane_y = oldplane_x * sin(-m->p->rs) + m->p->plane_y * cos(-m->p->rs);
		mlx_clear_window(m->mlx, m->win);
		draw_map(m);
	}
	if (keycode == L_ARROW)
	{
		olddir_x = m->p->dir_x;
		m->p->dir_x = m->p->dir_x * cos(m->p->rs) - m->p->dir_y * sin(m->p->rs);
		m->p->dir_y = olddir_x * sin(m->p->rs) + m->p->dir_y * cos(m->p->rs);
		oldplane_x = m->p->plane_x;
		m->p->plane_x = m->p->plane_x * cos(m->p->rs) - m->p->plane_y * sin(m->p->rs);
		m->p->plane_y = oldplane_x * sin(m->p->rs) + m->p->plane_y * cos(m->p->rs);
		mlx_clear_window(m->mlx, m->win);
		draw_map(m);
	}
	if (keycode == D)
	{
		if (m->p->map[(int)(m->p->pos_x + m->p->plane_x * m->p->ms)][(int)m->p->pos_y] == 0)
			m->p->pos_x += m->p->plane_x * m->p->ms;
		if (m->p->map[(int)(m->p->pos_x)][(int)(m->p->pos_y + m->p->plane_y * m->p->ms)] == 0)
			m->p->pos_x += m->p->plane_x * m->p->ms;
		mlx_clear_window(m->mlx, m->win);
		draw_map(m);
	}
	if (keycode == A)
	{
		if (m->p->map[(int)(m->p->pos_x - m->p->plane_x * m->p->ms)][(int)m->p->pos_y] == 0)
			m->p->pos_x -= m->p->plane_x * m->p->ms;
		if (m->p->map[(int)(m->p->pos_x)][(int)(m->p->pos_y - m->p->plane_y * m->p->ms)] == 0)
			m->p->pos_x -= m->p->plane_x * m->p->ms;
		mlx_clear_window(m->mlx, m->win);
		draw_map(m);
	}
}