/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:32:42 by rmaury            #+#    #+#             */
/*   Updated: 2015/10/27 11:07:51 by rmaury           ###   ########.fr       */
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
	int		n;
	int		**map;
	int		line;

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
	map = (int**)malloc(sizeof(int*) * line + 1);
	line = 0;
	while (m[i])
	{
		n = 0;
		while (m[x + i] != '\n' && m[x + i])
			x++;
		map[line] = (int*)malloc(sizeof(int) * x);
		while (n < x)
		{
			if (m[i] == '1' || m[i] == '0')
				map[line][n] = m[i] - '0';
			n++;
			i++;
		}
		i++;
		line++;
		x = 0;
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
	int		i;
	int		j;
	int		**map;
	char	*path;

	j = 0;
	i = 0;
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