/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/11/04 16:46:54 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// void	put_pixel_to_image(t_mlx *m, int *color, int x, int y)
// {
// 	m->p = y * m->sizeline + (m->bpp / 8) * x;
// 	ft_memcpy(&e->data[e->p], color, (e->bpp / 8));
// }

int		expose_hook(t_mlx *mlx)
{
	return (0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		free(mlx->p->map);
		free(mlx->p);
		free(mlx);
		exit(0);
	}
	move(mlx, keycode);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->p = (t_player*)malloc(sizeof(t_player));
	mlx->width = 1200;
	mlx->heigh = 800;
	mlx->p->pos_x = 5;
	mlx->p->pos_y = 5;
	mlx->p->dir_x = -1;
	mlx->p->dir_y = 0;
	mlx->p->plane_x = 0;
	mlx->p->plane_y = 0.66;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->heigh, "wolf3d");
	mlx->p->map = map_select(1, mlx->mlx, mlx->win);
	mlx_expose_hook(mlx->win, expose_hook, mlx);
	mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, key_hook, mlx);
	// mlx_get_data_addr(mlx->img, mlx->&bpp, mlx->&sizeline, mlx->&endian);
	draw_map(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 150, 35, 65280, WELCOME);
	mlx_loop(mlx->mlx);
	return (0);
}
