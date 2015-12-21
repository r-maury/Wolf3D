/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:24:04 by rmaury            #+#    #+#             */
/*   Updated: 2015/12/04 13:01:23 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_itoacounter(int n)
{
	int		size;

	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	unsigned int	size;
	char			*str;
	int				i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_itoacounter(n);
	i = n;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		if (n < 0)
			n = -n;
		str[size] = n % 10 + '0';
		n = n / 10;
	}
	if (i < 0)
		str[0] = '-';
	return (str);
}
