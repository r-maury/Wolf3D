/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 17:46:05 by rmaury            #+#    #+#             */
/*   Updated: 2015/09/25 19:35:54 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	draw_map(t_player *p)
{
	int x;
	int w;
	int cam_x;
	int step_x;
	int step_y;
	int hit;
	int side;
	double rayp_x;
	double rayp_y;
	double rayd_x;
	double rayd_y;
	double sidedist_x;
	double sidedist_y;
	double deltadist_x;
	double deltadist_y;
	double perpwalldist;

	cam_x = (2 * x / w) - 1;
	rayp_y = p.pos_y;
	rayp_x = p.pos_x;
	rayd_y = p.dir_y + p.plane_y * cam_x;
	rayd_x = p.dir_x + p.plane_x * cam_x;
	x = 0;
	w = 512;
	hit = 0;
		while (x < w)
	{
		p.map_x = (int)rayp_x;
		p.map_y = (int)rayp_y;
		deltadist_x = sqrt(1 + (rayd_y * rayd_y) / (rayd_x * rayd_x));
		deltadist_y = sqrt(1 + (rayd_x * rayd_x) / (rayd_y * rayd_y));
		if (rayd_x < 0)
		{
			step_x = -1;
			sidedist_x = (rayp_x - p.map_x) * deltadist_x;
		}
		else
			{
				step_x = 1;
				sidedist_x = (p.map_x + 1.0 - rayp_x) * deltadist_x;
			}
		if (rayd_y < 0)
		{
			step_y = -1;
			sidedist_y = (rayp_x - p.map_y) * deltadist_y;
		}
		else
		{
			step_y = 1;
			sidedist_y = (p.map_y + 1.0 - rayp_y) *deltadist_y;
		}
		while (hit == 0)
		{
			if (sidedist_x < sidedist_y)
			{
				sidedist_x += deltadist_x;
				p.map_x += step_x;
				side = 0;
			}
			else
			{
				sidedist_y += deltadist_y;
				p.map_y += step_y;
				side = 1;
			}
			if (p.map[p.map_x][p.map_y] > 0)
				hit = 1;
		}
	}
}

























