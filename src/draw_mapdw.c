/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 17:46:05 by rmaury            #+#    #+#             */
/*   Updated: 2015/11/04 16:50:22 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	ft_rays(t_mlx *m)
{

}

void	draw_map(t_mlx *m)
{
	int x;
	int y;


	x = 0;
	y = 0;
	while (x < m->width)
	{
		m->cam_x = (2 * x / (double)m->width) - 1;
		m->rayp_y = m->p->pos_y;
		m->rayp_x = m->p->pos_x;
		m->rayd_y = m->p->dir_y + m->p->plane_y * m->cam_x;
		m->rayd_x = m->p->dir_x + m->p->plane_x * m->cam_x;
		m->hit = 0;
		m->p->map_x = (int)m->rayp_x;
		m->p->map_y = (int)m->rayp_y;
		m->deltadist_x = sqrt(1 + (m->rayd_y * m->rayd_y) / (m->rayd_x * m->rayd_x));
		m->deltadist_y = sqrt(1 + (m->rayd_x * m->rayd_x) / (m->rayd_y * m->rayd_y));
		if (m->rayd_x < 0)
		{
			m->step_x = -1;
			m->sidedist_x = (m->rayp_x - m->p->map_x) * m->deltadist_x;
		}
		else
		{
			m->step_x = 1;
			m->sidedist_x = (m->p->map_x + 1.0 - m->rayp_x) * m->deltadist_x;
		}
		if (m->rayd_y < 0)
		{
			m->step_y = -1;
			m->sidedist_y = (m->rayp_y - m->p->map_y) * m->deltadist_y;
		}
		else
		{
			m->step_y = 1;
			m->sidedist_y = (m->p->map_y + 1.0 - m->rayp_y) * m->deltadist_y;
		}
		while (m->hit == 0)
		{
			if (m->sidedist_x < m->sidedist_y)
			{
				m->sidedist_x += m->deltadist_x;
				m->p->map_x += m->step_x;
				m->side = 0;
			}
			else
			{
				m->sidedist_y += m->deltadist_y;
				m->p->map_y += m->step_y;
				m->side = 1;
			}
			if (m->p->map[m->p->map_x][m->p->map_y] == 1)
				m->hit = 1;
		}
		if (m->side == 0)
		{
			m->perpwalldist = fabs((m->p->map_x - m->rayp_x + (1 - m->step_x) / 2) / m->rayd_x);
			m->side = (m->step_x < 0) ? 0 : 1;
		}
		else
		{
			m->perpwalldist = fabs((m->p->map_y - m->rayp_y + (1 - m->step_y) / 2) / m->rayd_y);
			m->side = (m->step_y < 0) ? 2 : 3;
		}
		m->line_h = abs((int)(m->heigh / m->perpwalldist));
		m->draw_start = -m->line_h / 2 + m->heigh / 2;
		m->draw_end = m->line_h / 2 + m->heigh / 2;
		if (m->draw_start < 0)
			m->draw_start = 0;
		if (m->draw_end >= m->heigh)
			m->draw_end = m->heigh - 1;
		y = m->draw_start;
		while (y < m->draw_end)
		{
			m->color = 0xf2f2f2;
			if (m->side == 1)
				m->color = 0xCCCCCC;
			if (m->side == 2)
				m->color = 0xCC00FF;
			if (m->side == 3)
				m->color = 0xCC0033;
			mlx_pixel_put(m->mlx, m->win, x, y, m->color);
			y++;
		}
		if (m->draw_end < 0)
			m->draw_end = m->heigh;
		y = m->draw_end;
		while (y < m->heigh)
		{
			mlx_pixel_put(m->mlx, m->win, x, y, 0x009933);
			mlx_pixel_put(m->mlx, m->win, x, m->heigh - y - 1, 0xC8FAFF);
			y++;
		}
		x++;
	}
}

























