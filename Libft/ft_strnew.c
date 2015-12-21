/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:48:36 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/13 00:11:34 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		return (ft_strdup(""));
	str = (char*)ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	else
		return (str);
}
