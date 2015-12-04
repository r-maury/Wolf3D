/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 17:46:05 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/04 18:21:06 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel_to_image(t_mlx *m, int *color, int x, int y)
{
	m->pix = y * m->sizeline + (m->bpp / 8) * x;
	ft_memcpy(&m->data[m->pix], color, (m->bpp / 8));
}

void	set_color(t_mlx *m, int y)
{
	if (y < m->draw_start)
		m->color = 3355545;
	else if (y >= m->draw_start && y < m->draw_end)
	{
		if (m->side == 0)
			m->color = 16777030;
		else if (m->side == 1)
			m->color = 13421772;
		else if (m->side == 2)
			m->color = 13369599;
		else if (m->side == 3)
			m->color = 13369395;
	}
	else if (y >= m->draw_end && y < m->heigh)
		m->color = 39219;
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

static void	draw_var_init(t_mlx *m, int x)
{
	m->cam_x = (2.0 * x / (double)m->width) - 1.0;
	m->rayp_y = m->pos_y;
	m->rayp_x = m->pos_x;
	m->rayd_y = m->dir_y + m->plane_y * m->cam_x;
	m->rayd_x = m->dir_x + m->plane_x * m->cam_x;
	m->hit = 0;
	m->map_x = (int)m->rayp_x;
	m->map_y = (int)m->rayp_y;
	m->deltadist_x = sqrt(1 + (m->rayd_y * m->rayd_y) /
		(m->rayd_x * m->rayd_x));
	m->deltadist_y = sqrt(1 + (m->rayd_x * m->rayd_x) /
		(m->rayd_y * m->rayd_y));
}

void	draw_map(t_mlx *m)
{
	int x;

	x = 0;
	while (x < m->width)
	{
		draw_var_init(m, x);
		ft_rays(m);
		wall_dist(m);
		optical_corrector(m);
		set_heigh(m);
		put_column_to_image(m, x);
		x++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	check_pos(m);
}
