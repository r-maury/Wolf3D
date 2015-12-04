/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/04 12:54:37 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// void	switch_map(t_mlx *mlx, int keycode)
// {
// 	if (mlx->init == 1)
// 		free(mlx->map);
// 	if (keycode == 83 || keycode == 18)
// 	{
// 		mlx->map = map_select(1, mlx->mlx, mlx->win);
// 		init_wolf(mlx, 1);
// 		draw_map(mlx);
// 	}
// 	if (keycode == 84 || keycode == 19)
// 	{
// 		mlx->map = map_select(2, mlx->mlx, mlx->win);
// 		init_wolf(mlx, 2);
	
// 	}
// 	if (keycode == 85 || keycode == 20)
// 	{
// 		mlx->map = map_select(3, mlx->mlx, mlx->win);
// 		init_wolf(mlx, 3);
// 	}
// 	if (keycode == 86 || keycode == 21)
// 	{
// 		mlx->map = map_select(4, mlx->mlx, mlx->win);
// 		init_wolf(mlx, 4);
// 	}
// }

void	init_wolf(t_mlx *mlx, int map_nb)
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
	mlx->map_nb = map_nb;
	mlx->init = 1;
}

int		main(int ac, char **av)
{
	t_mlx mlx;
	(void)ac;
	(void)av;

	mlx.init = 0;
	init_wolf(&mlx, 1);
	if (!(mlx.mlx = mlx_init()))
	{
		ft_putendl("mlx_init error");
		exit(0);
	}
	mlx.win = mlx_new_window(mlx.mlx, 1200, 800, "wolf3d");
	mlx.map = map_select(1, mlx.mlx, mlx.win);
	mlx.img = mlx_new_image(mlx.mlx, 1200, 800);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sizeline, &mlx.endian);
	mlx_string_put(mlx.mlx, mlx.win, 150, 35, 65280, WELCOME);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
