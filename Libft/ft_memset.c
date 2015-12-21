/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:28:18 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/13 20:04:47 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sp;

	sp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		sp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
