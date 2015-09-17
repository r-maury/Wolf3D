/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:06:43 by rmaury            #+#    #+#             */
/*   Updated: 2015/09/17 16:25:48 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"


int	main()
{
	int x;
	double x_pos;
	double y_pos;
	double x_dir;
	double y_dir;
	double x_plane;
	double y_plane;
	double time;
	double prev_time;
	void *mlx;
	void *win;

	x_pos = 1;
	y_pos = 1;
	x_dir = -1;
	y_dir = 0;
	x_plane = 0;
	y_plane = 0.66;
	time = 0;
	prev_time = 0;
	x = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "wolf3d");
	// while (x < max)
	// {

	// }
	mlx_loop(mlx);

	return (0);
}