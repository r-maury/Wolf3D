/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 03:36:02 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/18 18:17:34 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	forward(t_mlx *m)
{
	if (m->map[(int)(m->pos_x + m->dir_x * m->ms)]
		[(int)m->pos_y] == 0)
		m->pos_x += m->dir_x * m->ms;
	if (m->map[(int)m->pos_x][(int)(m->pos_y + m->dir_y *
		m->ms)] == 0)
		m->pos_y += m->dir_y * m->ms;
	draw_map(m);
}

void	backward(t_mlx *m)
{
	if (m->map[(int)(m->pos_x - m->dir_x * m->ms)]
		[(int)m->pos_y] == 0)
		m->pos_x -= m->dir_x * m->ms;
	if (m->map[(int)m->pos_x][(int)(m->pos_y - m->dir_y *
		m->ms)] == 0)
		m->pos_y -= m->dir_y * m->ms;
	draw_map(m);
}

void	strafe_right(t_mlx *m)
{
	if (m->map[(int)(m->pos_x + m->plane_x * m->ms)]
		[(int)m->pos_y] == 0)
		m->pos_x += m->plane_x * m->ms;
	if (m->map[(int)(m->pos_x)][(int)(m->pos_y + m->plane_y *
		m->ms)] == 0)
		m->pos_y += m->plane_y * m->ms;
	draw_map(m);
}

void	strafe_left(t_mlx *m)
{
	if (m->map[(int)(m->pos_x - m->plane_x * m->ms)]
		[(int)m->pos_y] == 0)
		m->pos_x -= m->plane_x * m->ms;
	if (m->map[(int)(m->pos_x)][(int)(m->pos_y - m->plane_y *
		m->ms)] == 0)
		m->pos_y -= m->plane_y * m->ms;
	draw_map(m);
}

void	move(t_mlx *m, int keycode)
{
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
