/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:51:12 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/10 14:41:01 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		if (m->map[m->map_x][m->map_y] > 0)
			m->hit = 1;
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
		m->perpwalldist = fabs((m->map_x - m->rayp_x +
			(1 - m->step_x) / 2) / m->rayd_x);
		m->side = (m->step_x < 0) ? 0 : 1;
	}
	else
	{
		m->perpwalldist = fabs((m->map_y - m->rayp_y +
			(1 - m->step_y) / 2) / m->rayd_y);
		m->side = (m->step_y < 0) ? 2 : 3;
	}
}
