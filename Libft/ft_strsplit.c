/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:34:54 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/18 19:28:50 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_wordlen(const char *s, char c, int w_pos)
{
	unsigned int	start;
	unsigned int	end;

	start = w_pos;
	while (s[start] == c && s[start])
		start++;
	end = start;
	while (s[end] != c && s[end])
		end++;
	return (end + 1);
}

static char		*ft_wordalloc(const char *s, char c, int w_pos)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*str;

	i = 0;
	start = w_pos;
	while (s[start] == c && s[start])
		start++;
	end = start;
	while (s[end] != c && s[end])
		end++;
	str = (char*)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (i + start < end)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int		ft_wordcount(const char *s, char c)
{
	unsigned int	i;
	unsigned int	w_cnt;

	i = 0;
	w_cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			w_cnt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (w_cnt);
}

char			**ft_strsplit(const char *s, char c)
{
	unsigned int		w_pos;
	unsigned int		w_cnt;
	unsigned int		i;
	char				**tab;

	if (!s)
		return (NULL);
	i = 0;
	w_pos = 0;
	w_cnt = ft_wordcount(s, c);
	tab = ft_memalloc(sizeof(char*) * (w_cnt + 1));
	if (s[0] == '\0' || w_cnt == 0)
	{
		tab[0] = NULL;
		return (tab);
	}
	while (i < w_cnt)
	{
		tab[i] = ft_wordalloc(s, c, w_pos);
		w_pos = ft_wordlen(s, c, w_pos);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
