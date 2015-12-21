/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:04:01 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/13 00:03:22 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*sp;

	i = 0;
	sp = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&sp[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&sp[i]);
	return (NULL);
}
