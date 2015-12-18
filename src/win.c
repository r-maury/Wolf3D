/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:03:09 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/18 18:15:28 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_win(t_mlx *m)
{
	if ((int)m->pos_y == m->win_y && (int)m->pos_x == m->win_x)
		return (1);
	else
		return (0);
}

void	check_pos(t_mlx *m)
{
	char *nxt;
	char *win;
	char *over;

	win = "You have finished every maze hope you enjoyed :)";
	nxt = ft_strdup("Press n to go to the next lvl");
	over = "This Maze is over Congratz";
	if (m->init == 1)
	{
		if (m->map_nb != 4)
			nxt[6] = (m->map_nb + 1 + '0');
	}
	if ((int)m->pos_x == m->win_x && (int)m->pos_y == m->win_y)
	{
		mlx_string_put(m->mlx, m->win, 500, m->heigh / 2, 65280, over);
		if (m->map_nb != 4)
			mlx_string_put(m->mlx, m->win, 490, 420, 65280, nxt);
		else
			mlx_string_put(m->mlx, m->win, 430, 420, 65280, win);
	}
	free(nxt);
}
