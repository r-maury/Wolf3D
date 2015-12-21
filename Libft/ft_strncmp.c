/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:59:03 by rmaury            #+#    #+#             */
/*   Updated: 2014/12/10 20:06:24 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	i = 0;
	s1p = (unsigned char*)s1;
	s2p = (unsigned char*)s2;
	while (i < n && s1p[i] == s2p[i] && (s1p[i] && s2p[i]))
		i++;
	if (i == n)
		i--;
	return (s1p[i] - s2p[i]);
}
