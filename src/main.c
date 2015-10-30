/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/10/30 17:41:03 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		expose_hook(t_mlx *mlx)
{
	return (0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	move(mlx, keycode);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->p = (t_player*)malloc(sizeof(t_player));
	mlx->p->pos_x = 5;
	mlx->p->pos_y = 5;
	mlx->p->dir_x = -1;
	mlx->p->dir_y = 0;
	mlx->p->plane_x = 0;
	mlx->p->plane_y = 0.66;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 512, 384, "wolf3d");
	mlx->p->map = map_select(1, mlx->mlx, mlx->win);
	mlx_expose_hook(mlx->win, expose_hook, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	draw_map(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 150, 35, 65280, WELLCOME);
	mlx_loop(mlx->mlx);
	return (0);
}
