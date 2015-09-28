/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/09/28 19:18:14 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_mlx *mlx)
{
	return (0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_player	p;

	p.pos_x = 1;
	p.pos_y = 1;
	p.dir_x = -1;
	p.dir_y = 0;
	p.plane_x = 0;
	p.plane_y = 0.66;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 512, 384, "wolf3d");
	p.map = map_select(1, mlx.mlx, mlx.win);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}