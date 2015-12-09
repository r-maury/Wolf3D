/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/05 15:37:20 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_wolf(t_mlx *mlx)
{
	mlx->width = 1200;
	mlx->sizeline = mlx->width;
	mlx->heigh = 800;
	mlx->pos_x = 2;
	mlx->pos_y = 2;
	mlx->spawn_x = mlx->pos_x;
	mlx->spawn_y = mlx->pos_y;
	mlx->dir_x = -1;
	mlx->dir_y = 0;
	mlx->plane_x = 0;
	mlx->plane_y = 0.66;
	mlx->ms = 0.5;
	mlx->rs = 0.2;
}

void	switch_map(t_mlx *mlx, int keycode)
{

	if (keycode == 83 || keycode == 18)
		mlx->map_nb = 1;
	else if (keycode == 84 || keycode == 19)
		mlx->map_nb = 2;
	else if (keycode == 85 || keycode == 20)
		mlx->map_nb = 3;
	else if (keycode == 86 || keycode == 21)
		mlx->map_nb = 4;
	if (mlx->init == 1)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_image(mlx->mlx, mlx->img);
		init_wolf(mlx);
		free(mlx->map);
		mlx->init = 0;
	}
	mlx->map = map_select(mlx);
	draw_map(mlx);
}

int		main(int ac, char **av)
{
	t_mlx mlx;
	(void)ac;
	(void)av;

	mlx.init = 0;
	init_wolf(&mlx);
	if (!(mlx.mlx = mlx_init()))
	{
		ft_putendl("mlx_init error");
		exit(0);
	}
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.heigh, "wolf3d");
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.heigh);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sizeline, &mlx.endian);
	mlx_string_put(mlx.mlx, mlx.win, 500, 370, 65280, WELCOME);
	mlx_string_put(mlx.mlx, mlx.win, 440, 400, 65280, PRESS);
	mlx_string_put(mlx.mlx, mlx.win, 500, 430, 65280, ESC);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
