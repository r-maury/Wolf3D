/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:54:58 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/18 16:00:39 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*sp;

	sp = (char *)s;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return (sp + i);
	while (i > 0)
	{
		i--;
		if (sp[i] == (char)c)
			return (sp + i);
	}
	return (NULL);
}
