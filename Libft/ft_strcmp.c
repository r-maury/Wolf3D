/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:21:31 by rmaury            #+#    #+#             */
/*   Updated: 2014/12/10 20:09:30 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	i = 0;
	s1p = (unsigned char*)s1;
	s2p = (unsigned char*)s2;
	while (s1p[i] && s1p[i] == s2p[i])
		i++;
	return (s1p[i] - s2p[i]);
}
