/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:20:28 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/18 19:30:53 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = 0;
	len = ft_strlen(s) - 1;
	while ((s[start] == '\n' || s[start] == ' ' || s[start] == '\t')
			&& s[start])
		start++;
	while ((s[len] == '\n' || s[len] == ' ' || s[len] == '\t') && start < len)
		len--;
	str = (char*)malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	while (i <= len - start)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
