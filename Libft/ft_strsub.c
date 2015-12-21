/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:31:50 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/19 14:30:54 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s && start == 0 && len == 0)
		return (ft_strdup(""));
	if (s == NULL || (len + start - 1 > ft_strlen(s)))
		return (NULL);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	while (len--)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
