/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:04:44 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/12 23:58:19 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		d[len] = s[len];
	return (dst);
}
