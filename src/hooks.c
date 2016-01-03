/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:31:25 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/18 18:14:22 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	respawn(t_mlx *m)
{
	m->pos_x = m->spawn_x;
	m->pos_y = m->spawn_y;
	draw_map(m);
}

int		key_hook2(int keycode, t_mlx *mlx)
{
	if (keycode == 256)
	{
		if (mlx->ms == 0.5)
			mlx->ms = 1;
		else
			mlx->ms = 0.5;
	}
	return (0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		if (mlx->init == 1)
			free(mlx->map);
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(0);
	}
	if (keycode >= 83 && keycode <= 86)
	{
		switch_map(mlx, keycode);
		if (mlx->init == 0 || mlx->init == -1)
		{
			mlx->map = map_select(mlx);
			draw_map(mlx);
		}
	}
	if (mlx->init == 1)
		move(mlx, keycode);
	if (keycode == 17)
		respawn(mlx);
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_hook2, mlx);
	if (mlx->init == 1)
		draw_map(mlx);
	return (0);
}
