/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/11 16:58:16 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_wolf(t_mlx *mlx)
{
	mlx->width = 1200;
	mlx->sizeline = mlx->width;
	mlx->heigh = 800;
	mlx->ms = 0.5;
	mlx->rs = 0.2;
}

int		main(void)
{
	t_mlx mlx;

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
