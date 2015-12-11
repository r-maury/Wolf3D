/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:44:24 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/11 17:02:11 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free((void*)s1);
	return (str);
}

static int	line_count(char *m)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (m[i])
	{
		if (m[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

int			**map_get(int fd)
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

void		map_error(void)
{
	int	i;

	i = 10;
	ft_putendl("Error: File Not Found");
	ft_putstr("Exit in : ");
	while (i--)
	{
		ft_putnbr(i);
		if (i != 0)
			ft_putstr("...");
		sleep(1);
	}
	ft_putchar('\n');
	exit(0);
}
