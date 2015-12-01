/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:31:25 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/01 14:10:49 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_hook2(int keycode, t_mlx *mlx)
{
	if (keycode == 258)
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
		free(mlx->map);
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	move(mlx, keycode);
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_hook2, mlx);
	draw_map(mlx);
	return (0);
}