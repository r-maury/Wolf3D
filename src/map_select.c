/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:32:42 by rmaury            #+#    #+#             */
/*   Updated: 2015/11/30 18:47:29 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free((void*)s1);
	return (str);
}

static int	**fill_map_array(char *m, int line, int **map)
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

static int	line_count(char *m)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
		while (m[i])
	{
		if (m[i] != '\n' && m[i] != '0' && m[i] != '1' && m[i] != '2')
			m[i] = '1';
		if (m[i] == '\n')
			line ++;
		i++;
	}
	return (line);
}

static int	**map_get(int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*m;
	int		i;
	int		**map;
	int		line;

	m = ft_strdup(""); 
	while ((i = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[i] = 0;
		m = ft_strjoin_free(m, buff);
	}
	i = 0;
	line = 0;
	line = line_count(m);
	map = (int**)malloc(sizeof(int*) * line + 1);
	line = 0;
	map = fill_map_array(m, line, map);
	free(m);
	return (map);
}

static char	*make_path(char *path, int n)
{
	char *nb;

	nb = ft_itoa(n);
	path = ft_strjoin("./maps/map", nb);
	free(nb);
	return (path);
}

int			**map_select(int n, void *mlx, void *win)
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
	close(fd);
	free(path);
	return (map);
}