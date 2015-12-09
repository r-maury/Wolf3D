/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:32:42 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/09 17:51:39 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	**fill_map_array(char *m, int line, int **map)
{
	int	n;
	int	x;
	int	i;

	n = 0;
	x = 0;
	i = 0;
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

static char	*make_path(int n)
{
	char *nb;
	char *path;

	nb = ft_itoa(n);
	path = ft_strjoin("./maps/map", nb);
	free(nb);
	return (path);
}

int			**map_select(t_mlx *m)
{
	int		fd;
	int		**map;
	char	*path;

	path = make_path(m->map_nb);
	fd = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		map_error();
	map = map_get(fd);
	close(fd);
	free(path);
	return (map);
}