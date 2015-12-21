/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:40:32 by rmaury            #+#    #+#             */
/*   Updated: 2015/02/19 19:44:10 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_array(char *str, char **array)
{
	int		i;

	i = 0;
	if (str && array[0])
	{
		while (array[i])
		{
			if (ft_strncmp(str, array[i], ft_strlen(str)) == 0)
				return (i);
			i++;
		}
		return (-1);
	}
	return (-2);
}
