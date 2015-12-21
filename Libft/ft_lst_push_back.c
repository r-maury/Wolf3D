/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 14:57:04 by rmaury            #+#    #+#             */
/*   Updated: 2014/12/12 14:57:09 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if ((*alst) && new)
	{
		tmp = (*alst);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
