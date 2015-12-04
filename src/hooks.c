/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:31:25 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/04 18:53:16 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	respawn(t_mlx *m)
{
	m->pos_x = m->spawn_x;
	m->pos_y = m->spawn_y;
	mlx_clear_window(m->mlx, m->win);
	draw_map(m);
}

int		key_hook2(int keycode, t_mlx *mlx)
{
	if (keycode == 258)
	{
		if (mlx->ms == 0.5)
			mlx->ms = 1;
		else
			mlx->ms = 0.5;
	}
	if ((keycode >= 83 && keycode <= 86) || (keycode >= 18 && keycode <= 21))
		switch_map(mlx, keycode);
	if (keycode == 17)
		respawn(mlx);
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
		exit(0);
	}
	if (mlx->init == 1)
		move(mlx, keycode);
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_hook2, mlx);
	return (0);
}

void	check_pos(t_mlx *m)
{
	char *nxt;
	char *win;

	win = "You have finished every maze hope you enjoyed :)";
	nxt = ft_strdup("Press n to go to the next lvl");
	if (m->init == 1)
	{
		if (m->map_nb != 4)
			nxt[6] = (m->map_nb + 1 + '0');
	}
	if ((int)m->pos_y == 22 && (int)m->pos_y == 22)
	{
	 	mlx_string_put(m->mlx, m->win, 500, m->heigh / 2, 65280, "This Maze is over Congratz");
	 	if (m->map_nb != 4)
	 		mlx_string_put(m->mlx, m->win, 490, (m->heigh / 2) + 20, 65280, nxt);
	 	else
	 		mlx_string_put(m->mlx, m->win, 490, (m->heigh / 2) + 20, 65280, win);
	}
	free(nxt);
}