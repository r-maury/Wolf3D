/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 03:36:02 by rmaury            #+#    #+#             */
/*   Updated: 2015/11/04 17:25:32 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	forward(t_mlx *m)
{
	if (m->p->map[(int)(m->p->pos_x + m->p->dir_x * m->p->ms)]
		[(int)m->p->pos_y] == 0)
		m->p->pos_x += m->p->dir_x * m->p->ms;
	if (m->p->map[(int)m->p->pos_x][(int)(m->p->pos_y + m->p->dir_y *
		m->p->ms)] == 0)
		m->p->pos_y += m->p->dir_y * m->p->ms;
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}

void	backward(t_mlx *m)
{
	if (m->p->map[(int)(m->p->pos_x - m->p->dir_x * m->p->ms)]
		[(int)m->p->pos_y] == 0)
		m->p->pos_x -= m->p->dir_x * m->p->ms;
	if (m->p->map[(int)m->p->pos_x][(int)(m->p->pos_y - m->p->dir_y *
		m->p->ms)] == 0)
		m->p->pos_y -= m->p->dir_y * m->p->ms;
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}

void	strafe_right(t_mlx *m)
{
	if (m->p->map[(int)(m->p->pos_x + m->p->plane_x * m->p->ms)]
		[(int)m->p->pos_y] == 0)
		m->p->pos_x += m->p->plane_x * m->p->ms;
	if (m->p->map[(int)(m->p->pos_x)][(int)(m->p->pos_y + m->p->plane_y *
		m->p->ms)] == 0)
		m->p->pos_x += m->p->plane_x * m->p->ms;
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}

void	strafe_left(t_mlx *m)
{
	if (m->p->map[(int)(m->p->pos_x - m->p->plane_x * m->p->ms)]
		[(int)m->p->pos_y] == 0)
		m->p->pos_x -= m->p->plane_x * m->p->ms;
	if (m->p->map[(int)(m->p->pos_x)][(int)(m->p->pos_y - m->p->plane_y *
		m->p->ms)] == 0)
		m->p->pos_x -= m->p->plane_x * m->p->ms;
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}

void	move(t_mlx *m, int keycode)
{
	m->p->ms = 0.3;
	m->p->rs = 0.2;
	if (keycode == U_ARROW || keycode == W)
		forward(m);
	if (keycode == D_ARROW || keycode == S)
		backward(m);
	if (keycode == R_ARROW || keycode == E)
		right_rot(m);
	if (keycode == L_ARROW || keycode == Q)
		left_rot(m);
	if (keycode == D)
		strafe_right(m);
	if (keycode == A)
		strafe_left(m);
}
