/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:32:42 by rmaury            #+#    #+#             */
/*   Updated: 2015/09/28 19:53:17 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		**map_get(int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*m;
	int		i;
	int		x;
	int		**map;
	int		line;

	i = 0;
	x = 0;
	line = 0;
	m = "";
	while ((i = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[i] = 0;
		m = ft_strjoin(m, buff);
	}
	i = 0;
	while (m[i])
	{
		if (m[i] != '\n' && m[i] != '0' && m[i] != '1')
			m[i] = '1';
		if (m[i] == '\n')
			line ++;
		i++;
	}
	i = 0;
	map = (int**)malloc(sizeof(int*) * line);
	line = 0;
	while (m[i])
	{
		while (m[i] != '\n')
		{
			x++;
			i++;
		}
		i = 0;
		map[line] = (int*)malloc(sizeof(int) * x);
		while (i < x)
		{
			map[line][i] = ft_atoi(&m[i]);
			i++;
		}
		x++;
		i = x;
		x = 0;
		line++;
	}
	for(int i = 0; i < 24; i++)
	{
		for(int j = 0; j < 24; j++)
			printf("%d ", map[i][j]);
	printf("\n");
	}
	return (map);
}

char	*make_path(char *path, int n)
{
	char *nb;

	nb = ft_itoa(n);
	path = ft_strjoin("./maps/map", nb);

	return (path);
}

int		**map_select(int n, void *mlx, void *win)
{
	int		fd;
	int		**map;
	char	*path;

	path = make_path(path, n);
	fd = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		mlx_string_put(mlx, win, 190, 150, 16711680,"Error: File Not Found");
		ft_putendl("Error: File Not Found");
	}
	map = map_get(fd);
	return (map);
}