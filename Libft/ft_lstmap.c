/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:09:35 by rmaury            #+#    #+#             */
/*   Updated: 2014/11/24 17:57:46 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;

	new = NULL;
	if (lst != NULL)
		new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (NULL);
	new = f(new);
	if (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
