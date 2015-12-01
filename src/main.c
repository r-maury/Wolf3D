/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/01 14:24:35 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_wolf(t_mlx *mlx)
{
	mlx->width = 1200;
	mlx->sizeline = mlx->width;
	mlx->heigh = 800;
	mlx->pos_x = 2;
	mlx->pos_y = 2;
	mlx->dir_x = -1;
	mlx->dir_y = 0;
	mlx->plane_x = 0;
	mlx->plane_y = 0.66;
	mlx->ms = 0.5;
	mlx->rs = 0.2;
	if (!(mlx->mlx = mlx_init()))
	{
		ft_putendl("mlx_init error");
		exit(0);
	}
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->heigh, "wolf3d");
	mlx->map = map_select(1, mlx->mlx, mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->heigh);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
}

int		main(int ac, char **av)
{
	t_mlx mlx;
	(void)ac;
	(void)av;

	init_wolf(&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 150, 35, 65280, WELCOME);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
