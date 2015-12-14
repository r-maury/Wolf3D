/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/14 18:03:47 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_wolf(t_mlx *mlx)
{
	mlx->width = 1200;
	mlx->sizeline = mlx->width;
	mlx->heigh = 800;
	mlx->ms = 0.5;
	mlx->rs = 0.1;
}

int		main(void)
{
	t_mlx *m;

	m = (t_mlx*)malloc(sizeof(t_mlx));
	init_wolf(m);
	if (!(m->mlx = mlx_init()))
	{
		ft_putendl_fd("mlx_init error", 2);
		return (0);
	}
	m->win = mlx_new_window(m->mlx, m->width, m->heigh, "wolf3d");
	m->img = mlx_new_image(m->mlx, m->width, m->heigh);
	m->data = mlx_get_data_addr(m->img, &m->bpp, &m->sizeline, &m->endian);
	mlx_string_put(m->mlx, m->win, 500, 370, 65280, WELCOME);
	mlx_string_put(m->mlx, m->win, 440, 400, 65280, PRESS);
	mlx_string_put(m->mlx, m->win, 500, 430, 65280, ESC);
	mlx_expose_hook(m->win, expose_hook, m);
	mlx_hook(m->win, KEYPRESS, KEYPRESSMASK, key_hook, m);
	mlx_loop(m->mlx);
	return (0);
}
