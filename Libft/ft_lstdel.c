/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:11:04 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/24 18:39:23 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	if (alst && del)
	{
		lst = *alst;
		while (lst != NULL)
		{
			del(lst->content, lst->content_size);
			free(lst);
			lst = lst->next;
		}
		*alst = NULL;
	}
}
