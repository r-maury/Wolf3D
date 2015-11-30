/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 17:46:05 by rmaury            #+#    #+#             */
/*   Updated: 2015/11/30 16:08:20 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void		set_color(t_mlx *m, int y)
{
	if (y < m->draw_start)
		m->color = 39219;
	else if (y >= m->draw_start && y < m->draw_end)
	{
		if (m->side == 0)
			m->color = 15921906;
		else if (m->side == 1)
			m->color = 13421772;
		else if (m->side == 2)
			m->color = 13369599;
		else if (m->side == 3)
			m->color = 13369395;
	}
	else if	(y >= m->draw_end && y < m->heigh)
		m->color = 3355545;
}

void	wall_dist(t_mlx *m)
{
	while (m->hit == 0)
	{
		if (m->sidedist_x < m->sidedist_y)
		{
			m->sidedist_x += m->deltadist_x;
			m->map_x += m->step_x;
			m->side = 0;
		}
		else
		{
			m->sidedist_y += m->deltadist_y;
			m->map_y += m->step_y;
			m->side = 1;
		}
		if (m->map[m->map_x][m->map_y] == 1)
			m->hit = 1;
	}
}
void	put_column_to_image(t_mlx *m, int x)
{
	int	y;

	y = 0;
	set_color(m, y);
	while (y < m->draw_start)
	{
		put_pixel_to_image(m, &m->color, x, y);
		y++;
	}
	set_color(m, y);
	while (y < m->draw_end)
	{
		put_pixel_to_image(m, &m->color, x, y);
		y++;
	}
	set_color(m, y);
	while (y <= m->heigh)
	{
		put_pixel_to_image(m, &m->color, x, y);
		y++;
	}
}

void	ft_rays(t_mlx *m)
{
	if (m->rayd_x < 0)
	{
		m->step_x = -1;
		m->sidedist_x = (m->rayp_x - m->map_x) * m->deltadist_x;
	}
	else
	{
		m->step_x = 1;
		m->sidedist_x = (m->map_x + 1.0 - m->rayp_x) * m->deltadist_x;
	}
	if (m->rayd_y < 0)
	{
		m->step_y = -1;
		m->sidedist_y = (m->rayp_y - m->map_y) * m->deltadist_y;
	}
	else
	{
		m->step_y = 1;
		m->sidedist_y = (m->map_y + 1.0 - m->rayp_y) * m->deltadist_y;
	}
}

void	optical_corrector(t_mlx *m)
{
	if (m->side == 0)
	{
		m->perpwalldist = fabs((m->map_x - m->rayp_x + (1 - m->step_x) / 2) / m->rayd_x);
		m->side = (m->step_x < 0) ? 0 : 1;
	}
	else
	{
		m->perpwalldist = fabs((m->map_y - m->rayp_y + (1 - m->step_y) / 2) / m->rayd_y);
		m->side = (m->step_y < 0) ? 2 : 3;
	}
}

void	set_heigh(t_mlx *m)
{
	m->line_h = abs((int)(m->heigh / m->perpwalldist));
	m->draw_start = -m->line_h / 2 + m->heigh / 2;
	m->draw_end = m->line_h / 2 + m->heigh / 2;
	if (m->draw_start < 0)
		m->draw_start = 0;
	if (m->draw_end >= m->heigh)
		m->draw_end = m->heigh - 1;
}	

void	draw_map(t_mlx *m)
{
	int x;

	x = 0;
	while (x < m->width)
	{
		m->cam_x = (2.0 * x / (double)m->width) - 1.0;
		m->rayp_y = m->pos_y;
		m->rayp_x = m->pos_x;
		m->rayd_y = m->dir_y + m->plane_y * m->cam_x;
		m->rayd_x = m->dir_x + m->plane_x * m->cam_x;
		m->hit = 0;
		m->map_x = (int)m->rayp_x;
		m->map_y = (int)m->rayp_y;
		m->deltadist_x = sqrt(1 + (m->rayd_y * m->rayd_y) / (m->rayd_x * m->rayd_x));
		m->deltadist_y = sqrt(1 + (m->rayd_x * m->rayd_x) / (m->rayd_y * m->rayd_y));
		ft_rays(m);
		wall_dist(m);
		optical_corrector(m);
		set_heigh(m);
		put_column_to_image(m, x);
		x++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
}

























