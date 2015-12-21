/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:29:41 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/10 23:20:21 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i])
	{
		if (ft_strncmp(s1 + i, s2, ft_strlen(s2)) == 0)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
