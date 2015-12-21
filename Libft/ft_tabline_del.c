/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabline_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:16:51 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 17:27:25 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabline_del(char **tab, int pos)
{
	int		i;

	i = ft_tabline_count(tab);
	while (pos < i - 1)
	{
		tab[pos] = tab[pos + 1];
		pos++;
	}
	tab[i - 1] = NULL;
	return (tab);
}
