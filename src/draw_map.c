/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 17:46:05 by rmaury            #+#    #+#             */
/*   Updated: 2015/11/03 17:59:11 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>


void	draw_map(t_mlx *m)
{
	int x;
	int y;
	int w;
	int h;
	double cam_x;
	int step_x;
	int step_y;
	int hit;
	int side;
	int line_h;
	int draw_start;
	int draw_end;
	int color;
	double rayp_x;
	double rayp_y;
	double rayd_x;
	double rayd_y;
	double sidedist_x;
	double sidedist_y;
	double deltadist_x;
	double deltadist_y;
	double perpwalldist;

	w = 1200;
	h = 800;
	x = 0;
	y = 0;
	while (x < w)
	{
		cam_x = (2 * x / (double)w) - 1;
		rayp_y = m->p->pos_y;
		rayp_x = m->p->pos_x;
		rayd_y = m->p->dir_y + m->p->plane_y * cam_x;
		rayd_x = m->p->dir_x + m->p->plane_x * cam_x;
		hit = 0;
		m->p->map_x = (int)rayp_x;
		m->p->map_y = (int)rayp_y;
		deltadist_x = sqrt(1 + (rayd_y * rayd_y) / (rayd_x * rayd_x));
		deltadist_y = sqrt(1 + (rayd_x * rayd_x) / (rayd_y * rayd_y));
		if (rayd_x < 0)
		{
			step_x = -1;
			sidedist_x = (rayp_x - m->p->map_x) * deltadist_x;
		}
		else
		{
			step_x = 1;
			sidedist_x = (m->p->map_x + 1.0 - rayp_x) * deltadist_x;
		}
		if (rayd_y < 0)
		{
			step_y = -1;
			sidedist_y = (rayp_y - m->p->map_y) * deltadist_y;
		}
		else
		{
			step_y = 1;
			sidedist_y = (m->p->map_y + 1.0 - rayp_y) * deltadist_y;
		}
		while (hit == 0)
		{
			if (sidedist_x < sidedist_y)
			{
				sidedist_x += deltadist_x;
				m->p->map_x += step_x;
				side = 0;
			}
			else
			{
				sidedist_y += deltadist_y;
				m->p->map_y += step_y;
				side = 1;
			}
			if (m->p->map[m->p->map_x][m->p->map_y] == 1)
				hit = 1;
		}
		if (side == 0)
		{
			perpwalldist = fabs((m->p->map_x - rayp_x + (1 - step_x) / 2) / rayd_x);
			side = (step_x < 0) ? 0 : 1;
		}
		else
		{
			perpwalldist = fabs((m->p->map_y - rayp_y + (1 - step_y) / 2) / rayd_y);
			side = (step_y < 0) ? 2 : 3;
		}
		line_h = abs((int)(h / perpwalldist));
		draw_start = -line_h / 2 + h / 2;
		draw_end = line_h / 2 + h / 2;
		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= h)
			draw_end = h - 1;
		y = draw_start;
		while (y < draw_end)
		{
			color = 0xf2f2f2;
			if (side == 1)
				color = 0xCCCCCC;
			if (side == 2)
				color = 0xCC00FF;
			if (side == 3)
				color = 0xCC0033;
			mlx_pixel_put(m->mlx, m->win, x, y, color);
			y++;
		}
		if (draw_end < 0)
			draw_end = h;
		y = draw_end;
		while (y < h)
		{
			mlx_pixel_put(m->mlx, m->win, x, y, 0x009933);
			mlx_pixel_put(m->mlx, m->win, x, h - y - 1, 0xC8FAFF);
			y++;
		}
		x++;
	}
}

























