/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:32:42 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/14 17:09:39 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	col_count(char *m)
{
	int	i;

	i = 0;
	while (m[i] != '\n')
		i++;
	return (i);
}

int			**fill_map_array(char *m, int line, int **map)
{
	int	n;
	int	i;
	int	col;

	n = 0;
	i = 0;
	col = col_count(m);
	while (m[i])
	{
		n = 0;
		map[line] = (int*)malloc(sizeof(int) * col);
		while (n < col && m[i])
		{
			if (m[i] == '1' || m[i] == '0')
				map[line][n] = ft_chartoi(m[i]);
			n++;
			i++;
		}
		i++;
		line++;
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
	if ((fd = open(path, O_RDONLY)) < 0)
		map_error();
	map = map_get(fd);
	close(fd);
	free(path);
	return (map);
}
